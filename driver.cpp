#include <cstdlib>
#include "Cache.h"
#include <fstream> 
#include <string> 

using namespace std; 

int main(int argc, char* argv[]){
ifstream myFile(argv[1]); 
	
	int  capacity = -1; 
	int  blockSize = -1; 
	int  assoc = -1; 
	if(myFile.is_open()){
		int i = 0; 
		while(!myFile.eof()){
			myFile >> capacity;
			myFile >>  blockSize;  
			myFile >> assoc;
			
		
		}
	}
	Cache* myCache = new Cache();
	myCache->initialize(capacity, blockSize,assoc); 
	ifstream accessFile(argv[2]); 
	
	if(accessFile.is_open()){
		long long addr = -1;
		int counter = 0;  
		while(!accessFile.eof()){
			accessFile >>  addr; 
	//		cout << "address: " << addr << endl;  
			myCache->addAccess(addr,-1,-1); 
	//		cout << "Added to the cache " << endl; 
			myCache->printContents(); 
		}
	}
	
	myCache->printContents(); 
	myCache->printStatistics(); 
	delete myCache; 
	return 0; 
}
