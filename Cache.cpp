//Author: Nicholas Taylor 
#include "Cache.h" 

/*
 *Constructor for the Cache class. 
 */
Cache::Cache(){
	//Initializes each attribute of the Cache class. 
	numberOfAccesses = 0; 
	numberOfMisses = 0;
	capacity = -1; 
	block_size = -1; 
	associativity = -1;  
}

/*
 *Deconstructor 
 */
Cache::~Cache(){
	//Deallocate the dynamic array of Sets' 
	delete[] sets; 
}	

/*
 *Initializes the capacity, block_size, and set associativity of the cache. 
 */
void Cache::initialize(int capacity, int block_size, int assoc){
	//Checks if the capacity is a power of two and stores it in a boolean variable. 
	bool isCapacityPowerOfTwo = isAPowerOfTwo(capacity); 

	//Checks if the block_size is a power of two and stores it in a boolean variable. 
	bool isBlockSizePowerOfTwo = isAPowerOfTwo(block_size); 

 	//Checks if the associativity is a power of two and stores it in a boolean variable. 	
	bool isAssociativityPowerOfTwo = isAPowerOfTwo(assoc); 	

	//Multiplies the block_size and associativity and stores result in a long value. 
	long line_sizeXassoc = block_size * assoc; 
	
	//If bool value is false print error message for capacity. 
	if(isCapacityPowerOfTwo == false){ 
		std::cerr << "Capacity is not a power of two" << std::endl; 
		exit(1); 
	}
	
	//If bool value is false print error message for block_size. 
	if(isBlockSizePowerOfTwo == false){
		std::cerr << "Block_Size is not a power of two" << std::endl; 
		exit(1); 
	} 
	
	//If bool value is false print error message for associativity. 
	if(isAssociativityPowerOfTwo == false){
		std::cerr << "Associativity is not a power of two" << std::endl; 
		exit(1); 
	}
	
	//If the modulus of capacity by linesize * assoc is not 0 then print error message that linesize * assoc
	//is not divided equally in capacity.  
	if(capacity % line_sizeXassoc != 0 ){
		std::cerr << "Line size times associativity does not divides equally into capacity." << std::endl; 
		exit(1); 
	}
	//Sets the attributes of capacity, block_size, associativity in class from parameter values. 	 	
	this->capacity = capacity; 
	this->block_size = block_size; 
	this->associativity = assoc; 
	
	//Sets number of cache blocks using equation of capacity divided by block_size. 
	int numberCacheBlocks = capacity/ block_size;

	//Sets number of cache Sets using equation of numberCacheBlocks divided by associativity. 
	numberCacheSets = numberCacheBlocks / assoc;  

	//Sets the dynamic array of Sets size using numberCacheSets.  	
	sets = new Set[numberCacheSets]; 
	
	//Iterates through each of the sets in the Cache and sets the number of blocks each set contains. 
	for(int i =0; i < numberCacheSets; i++){
		sets[i].setNumberOfBlocks(assoc); 
	}
}

/*
 *Helper function that is passed a value and determines if that value is a power of two.
 *Returns a bool value if it is a power of two and false otherwise. 
 */
bool Cache::isAPowerOfTwo(int val){
	//Special case if the value is 0 then always false. 
	if(val == 0)
		return false; 

	//Special case if the value is 1 then always true. 
	if(val == 1)
		return true; 

	//If the value module by 2 is 0 then it is a power of two return true. 
	if(val % 2 == 0) 
		return true;
	
	//Otherwise return false. 
	return false;  
}

/*
 *print method that prints the statistics of the cache performance.
 *including the number of accesses, hits, misses, and hit rate. 
 */
void Cache::printStatistics(){
	//Gets the number of hits in the cache by subtracting the accesses by misses. 
	long long hits =  numberOfAccesses-numberOfMisses;

	//Gets hit rate by dividing the number hits by the number of accesses. 
	double hitRate = hits / (double) numberOfAccesses; 
	
	//prints cache performance. 
	std::cout<< "printStatistics" << std::endl;  
	std::cout<< "ACCESSES " << numberOfAccesses << std::endl; 
	std::cout<< "HITS " <<  hits << std::endl; 
	std::cout<< "MISSES " << numberOfMisses << std::endl; 
	std::cout<< "HIT RATE " << hitRate << std::endl; 
}

/*
 *Print method that prints the contents of the cache. 
 */
void Cache::printContents(){
	std::cout << "printContents" << std::endl; 
	//Iterates through each cache set and prints the content of the set. 
	for(int i=0; i<numberCacheSets; i++){
		std::cout << "******SET " << i << " ******" << std::endl; 
		//Each set has its own unique content so call set's print content method called printSet()
		//This prints the content information about the set. 
		sets[i].printSet(); 
		std::cout << "*****************" << std::endl; 
	}
}

/*
 *Adds memory addresses into the cache. 
 */
void Cache::addAccess(long long addr, int size, int type){	
	//Calculates the blockaddress from the byte address by dividing it by the blocksize. 
	long long blockAddress = (addr / block_size); 
	//Calculates the index by taking the blockaddress modulating it by the numberOfCache blocks and associativity.
	long long index =  (blockAddress%((capacity / block_size)/associativity)); 
	//Calculates the tag by taking blockAddress / dividing number of cache set and associativity. 
	long long tag = ((addr/block_size))/((capacity/block_size)/associativity); 	

	//Determines if the cache has a hit by calling the set index add access method to determine if the tag has a hit or miss. 
	//Then stores that result into the bool value hasHit. 
	bool hasHit = sets[index].addAccess(tag); 
	
	//Checks if it has missed. 
	//If it has increment number of misses. 
	if(!hasHit){
 		numberOfMisses++;
	}
	//always increment number of accesses. 
	numberOfAccesses++; 
}
