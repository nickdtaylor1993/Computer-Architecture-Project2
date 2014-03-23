#ifndef __CACHE_H__
#define __CACHE_H__
//Author: Nick Taylor

//Used for adding the memory acceses into the Cache class. 
#include <vector> 
//Used for printing the statistics and contents. 
#include <iostream>

//Used for representing a Block in a Cache. 
#include "Block.h" 

//Used for representing a Set in a Cache. 
#include "Set.h"  

#include <cstdlib> 

/*
 * Class used to simulate a cache which will be used in conjunction with Pin to 
 * analyze how different cache configurations work perform for different access
 * patterns. 
 */
class Cache{
	public: 
		/*
 		 *Constructor for the Cache
 		 */
		Cache(); 
		
		/*
 		 *Deconstructor for the Cache to deallocate the dynamic Set array. 
 		 */
		~Cache(); 
		
		/*
		 *Initializer method that initializes the information about the cache regarding its capacity
		 *block_size, and associativity. 
		 */
		void initialize(int capacity, int block_size, int assoc); 
		
		/*
 		 * Prints the statistics regarding on the number of accesses, misses, hits, and hit rate of the cache. 
 		 */ 
		void printStatistics(); 
		
		/*
 		 * Prints the contents of the cache in regards to each set in the cache. 
 		 * This includes index; tag; lru; and valid bit; 
 		 */
		void printContents(); 

		/*
 		 * Adds the access memory address into the cache. 
     		 */
		void addAccess(long long addr, int size, int type); 
		
		/*
 		 * Accessor method for getting number of misses. 
 		 */ 
		long long  getNumberMisses(){ return numberOfMisses;};

		/*
 		 * Accessor method for getting number of accesses.  
 		 */
		long long getNumberAccesses(){return numberOfAccesses;};  
		
	private:		
		//Create an array of sets.
		Set* sets; 
		
		//Checks if value is a power of two. 
		bool isAPowerOfTwo(int val); 	
		
		//Attribute for the number of Accesses, 
		long long numberOfAccesses; 
		
		//Attribute for the number of Misses. 
		long long numberOfMisses;

		int numberCacheSets; 
		//Attribute for the capacity of the Cache. 	
		int capacity; 

		//Attribute for the block_size of the Cache. 	
		int block_size; 

		//Attribute for the associativity of the Cache. 
		int associativity; 
}; 		
#endif 
