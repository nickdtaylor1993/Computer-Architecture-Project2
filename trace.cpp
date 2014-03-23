#include <iostream>
#include "pin.H"
#include "instlib.H"
#include "Cache.h"

using namespace INSTLIB;

CONTROL control;

// Variable is used to control whether cache contents are displayed to
// stdout after every non-stack memory access.  Set to 0 to not print
// values.
const int DEBUG_PRINT = 1;

// For determining starting and ending instruction addresses
long actualStartPC = 0;
UINT64 actuallyStarted = 0;

struct MemoryAccess{
  long long addr;
  int size;
  int type;
  int loc;
};

Cache *myCache=0;
UINT64 numInstructions = 0;

FILE *traceFile = 0;

MemoryAccess memAccess[3];  // up to 3 memory accesses per instruction
int numMemAccesses = 0;

const UINT64 STACK_OFFSET = 4192;
const int STACK = 1;
const int READ = 0;
const int WRITE = 1;

// This knob is added because any code executed prior to the start of
// instrumentation will not be instrumented when it executes during 
// the instrumented portion of the code.  Thus, you must start instrumenting
// earlier, just not actually counting any information for that earlier 
// period.

KNOB<UINT64> KnobActualStart(KNOB_MODE_WRITEONCE, "pintool",
			      "actual_start", "0", 
			      "Actual address to start counting");


VOID updateState(VOID *pc, THREADID tid)
{

  if((long)pc == actualStartPC){
    actuallyStarted++;// This keeps begin and end points at the same ip address
  }

  if(actuallyStarted == 1){  
    if(numMemAccesses > 0){
      fprintf(traceFile, "PC 0x%lx \t", (long)pc);
      for(int i = 0; i < numMemAccesses; i++){  // print memory accesses
	fprintf(traceFile, "ADDR 0x%llx %d %d\t", 
		memAccess[i].addr, memAccess[i].size, 
		memAccess[i].type);
	// Size refers to the number of bytes being accessed.  (Think lb vs. lw.)
	// Type refers to whether it is a read or write request.  (This lw vs. sw.)
	// For this assignment, your cache will not need to use the size or the
	// type parameters. 
	myCache->addAccess(memAccess[i].addr, memAccess[i].size, memAccess[i].type);

	if(DEBUG_PRINT == 1){
	  // For debugging purposes.  
	  fprintf(stdout, "ADDR 0x%llx %d %d\n", 
		  memAccess[i].addr, memAccess[i].size, 
		  memAccess[i].type);
	  myCache->printContents();
	}
      }
      fprintf(traceFile, "\n");
    }
  }
  else if(actuallyStarted > 1){
    fflush(0);
    PIN_Detach();
  }

  // clear variables of information for this instruction
  numMemAccesses = 0;

  // increment number of instructions
  numInstructions++;
  
}

VOID writeAddr(ADDRINT addr, ADDRINT size, ADDRINT ebp, ADDRINT esp, THREADID tid, BOOL stack)
{
  int stack_access = 0;

  if(stack == true) stack_access = 1;

  // get register values and check to see if it's a stack access (if stack, set to 1)
  if( ( (addr <= ebp) && (addr >= esp) ) )//
    stack_access = 1;
  else if( ( ( (addr - ebp) >= 0) && ( (addr - ebp) < STACK_OFFSET) )  ||
	   ( ( (ebp - addr) >= 0) && ( ( ebp - addr) < STACK_OFFSET) ) )
    stack_access = 1;
  else if( ( ( (esp - addr >= 0) && ( (esp - addr) < STACK_OFFSET) )) ||
	   ( ( (addr - esp ) >= 0 && ( (addr - esp) < STACK_OFFSET) ) ) )
    // New addition since some things weren't being seen as stack accesses
    stack_access = 1;

  if(stack_access == 0){
    memAccess[numMemAccesses].addr = addr;
    memAccess[numMemAccesses].size = size ;
    memAccess[numMemAccesses].type = WRITE; 
    memAccess[numMemAccesses].loc = stack_access;
    numMemAccesses++;  
  }
}

VOID readAddr(ADDRINT addr, ADDRINT size, ADDRINT ebp, ADDRINT esp, THREADID tid, BOOL stack)
{
  int stack_access = 0;

  if(stack == true) stack_access = 1;

  // get register values and check to see if it's a stack access (if stack, set to 1)
  if( ( (addr <= ebp) && (addr >= esp) ) )//
    stack_access = 1;
  else if( ( ( (addr - ebp) >= 0) && ( (addr - ebp) < STACK_OFFSET) )  ||
	   ( ( (ebp - addr) >= 0) && ( ( ebp - addr) < STACK_OFFSET) ) )
    stack_access = 1;
  else if( ( ( (esp - addr >= 0) && ( (esp - addr) < STACK_OFFSET) )) ||
	   ( ( (addr - esp ) >= 0 && ( (addr - esp) < STACK_OFFSET) ) ) )
    // New addition since some things weren't being seen as stack accesses
    stack_access = 1;

  if(stack_access == 0){
    memAccess[numMemAccesses].addr = addr;
    memAccess[numMemAccesses].size = size ;
    memAccess[numMemAccesses].type = READ;
    memAccess[numMemAccesses].loc = stack_access;
    
    numMemAccesses++;  
  }
}


// Pin calls this function every time a new instruction is encountered
VOID Instruction(INS ins, VOID *v)
{

  if(INS_IsMemoryWrite(ins)){
    bool stack = INS_IsStackWrite(ins);
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)writeAddr, IARG_MEMORYWRITE_EA, IARG_MEMORYWRITE_SIZE, 
		   //IARG_REG_VALUE, REG_EBP, IARG_REG_VALUE, REG_ESP, 
		   IARG_REG_VALUE, REG_GBP, IARG_REG_VALUE, REG_STACK_PTR,
		   IARG_THREAD_ID, IARG_BOOL, stack, IARG_END);
  }
  
  if(INS_IsMemoryRead(ins)){
    bool stack = INS_IsStackRead(ins);
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)readAddr, IARG_MEMORYREAD_EA, IARG_MEMORYREAD_SIZE, 
		   //IARG_REG_VALUE, REG_EBP, IARG_REG_VALUE, REG_ESP, 
		   IARG_REG_VALUE, REG_GBP, IARG_REG_VALUE, REG_STACK_PTR,
		   IARG_THREAD_ID, IARG_BOOL, stack, IARG_END);
  }
  if(INS_HasMemoryRead2(ins)){
    bool stack = INS_IsStackRead(ins);
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)readAddr, IARG_MEMORYREAD2_EA, IARG_MEMORYREAD_SIZE, 
		   //IARG_REG_VALUE, REG_EBP, IARG_REG_VALUE, REG_ESP, 
		   IARG_REG_VALUE, REG_GBP, IARG_REG_VALUE, REG_STACK_PTR,
		   IARG_THREAD_ID, IARG_BOOL, stack, IARG_END);
  }

  INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)updateState, IARG_INST_PTR, IARG_THREAD_ID, IARG_END);



}
	  
void PrintStats()
{
  fflush(0);
  fprintf(stderr, "Finished with code \n");

  fflush(0);
  myCache->printStatistics();
  long long accesses = myCache->getNumberAccesses();
  long long misses = myCache->getNumberMisses();

  fflush(0);
  fprintf(stdout, "ACCESS FREQ %f\n", (float)accesses/(float)numInstructions);
  fprintf(stdout, "CPI for miss latency = 10 cycles %f\n", (1+ 10*( (float)misses/(float)numInstructions)));
  
  if(traceFile)
    fclose(traceFile);

  fflush(0);
}


// This function is called when the application exits
VOID ByeWorld(VOID *v)  // knobs
{
  fprintf(stderr, "In ByeWorld\n");
  PrintStats();
}

// This function is called when the application exits
VOID Fini(INT64 code, VOID *v) // no knobs
{
    fprintf(stderr, "In Fini\n" );
    PrintStats();
}

VOID Handler(CONTROL_EVENT ev, VOID *v, CONTEXT *ctxt, VOID *ip, THREADID tid)
{
  fprintf(stderr, "IN HANDLER 0x%llx\n", (unsigned long long) ip);
  switch(ev){
  case CONTROL_START:
    fprintf(stderr, "Start 0x%llx\n", (unsigned long long)ip);
    fprintf(stderr, "Actual 0x%llx\n", (unsigned long long)actualStartPC);
    // Register Instruction to be called to instrument instructions
    //    INS_AddInstrumentFunction(Instruction, 0);
    break;
  case CONTROL_STOP:
    fprintf(stderr, "Stop 0x%llx\n", (unsigned long long)ip);
  // Register Fini to be called when the application exits
    //PIN_RemoveFiniFunctions();
    actuallyStarted++;
    //    PIN_Detach();

    break;
  default:
    ASSERTX(false);
    break;
  }
  
}


// argc, argv are the entire command line, including pin -t <toolname> -- ...
int main(int argc, char * argv[])
{
  traceFile = fopen("traceFile.out" ,"w");
  if(traceFile == 0){
    fprintf(stderr, "Unable to open tracefile \n" );
  } 

  int capacity = 0, block_size = 0, associativity = 1;
  FILE *configFile = fopen("config.txt", "r");
  if(configFile == 0){
    fprintf(stderr, "Unable to open config.txt to configure cache \n");
    exit(1);
  }
  fscanf(configFile, "%d %d %d", &capacity, &block_size, &associativity);
  fclose(configFile);

  myCache = new Cache();
  myCache->initialize(capacity, block_size, associativity);

  // Initialize pin
  PIN_Init(argc, argv);

  // To avoid start up stuff
  control.CheckKnobs(Handler,  0);

  actualStartPC = KnobActualStart.Value();
  if(actualStartPC == 0)
    actuallyStarted = 1;  // start things immediately
  // end avoid start up stuff
  
  INS_AddInstrumentFunction(Instruction, 0);

    // If you use start and stop knobs
  PIN_AddDetachFunction(ByeWorld, 0);  

  // Start the program, never returns
  PIN_StartProgram();
  
  return 0;
}
