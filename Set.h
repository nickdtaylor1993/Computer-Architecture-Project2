#ifndef __SET_H__
#define __SET_H__
//Author:Nick Taylor 

//Used for accessing block class methods. 
#include "Block.h"

//Used for printing set content information. 
#include <iostream> 

/*
 * Set class is used to represent the Sets's that are included within the cache. 
 */
class Set{
	public:
		/*
 		 *Constructor for the Set class. 
 		 */
		Set(); 
		
		/*
 		 *Deconstructor for the Set class. 
 		 */ 
		~Set(); 
		
		/*
 		 *Sets the number of blocks in the set. 
 		 */ 
		void setNumberOfBlocks(int size); 
		
		/*
 		 *Prints the content of the set. 
 		 */
		void printSet();  

		/*
 		 *Add Access method for determining if the tag is inside the cache set. 
 		 */
		bool addAccess(long long tag); 	
		
	private:
		//Dynamic allocated array of Blocks's 
		Block* blocks; 
		//Attribute for the number of blocks in the set. 
		int numBlocks;
		//Helper method used to update the lru's of the Set's blocks if the set has a hit. 
		void updateLruHit(int index); 
		//Helper method used to update the lru's of the Set's blocks if the set has a miss. 
		void updateLruMiss(long long tag);  
		//Helper method used to find the highest lru value in the set: (highest lru means least frequently used in this context.) 
		int findHighestLru(); 
		//Attribute for keeping track of the lru. 
		int lruChecker;  
};
#endif
