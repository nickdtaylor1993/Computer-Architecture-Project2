//Author:Nick Taylor
#include "Set.h"

/*
 *Default constructor. 
 */
Set::Set(){}

/*
 *Used to set the number of blocks in the size by passing in the size as a parameter.
 */
void Set::setNumberOfBlocks(int size){
	//Sets the size of the dynamic block array in the Set. 
	blocks = new Block[size]; 
	//Set the number of blocks with the size passed in. 
	numBlocks = size;
	//Init the lruChecker to default. 
	lruChecker = 0;  
	//Iterate through the blocks in the Set and set its index value and lru to -1. 
	for(int i = 0; i < numBlocks; i++){
		blocks[i].setIndex(i);
		blocks[i].setLru(-1);  
	 }
}

/*
 *Deconstructor for the Set class. 
 */
Set::~Set(){
	//Deallocates the dynamic block array. 
	delete[] blocks;
}

/*
 *Prints the content of the Set:
 */
void Set::printSet(){
	//Iterates through each of the blocks in the set and prints the index, tag, valid bit, and lru. 
	for(int i = 0; i < numBlocks; i++){
		 std::cout << "Index " << blocks[i].getIndex() << ": tag " <<  std::hex << blocks[i].getTag() << std::dec << " valid " << blocks[i].getValidBit() << " lru " << blocks[i].getLru() << std::endl; 
	}
}

/*
 * Checks in the Set to see if the data is in the cache
 */
bool Set::addAccess(long long tag){
	//Checks if the block has a hit and updates the lru.  
	for(int j=0; j < numBlocks; j++){
		//Checks if the tag is in the set and if the block has a valid lru. 
		if((blocks[j].getTag() == tag) && (blocks[j].getLru() != -1)){
			//Updates the Set with the hit case. 
			//returns true that there was a hit in the set. 
			updateLruHit(j); 
			return true; 
		}
	}

	//Goes through the blocks in the set 	
	for(int i=0; i < numBlocks; i++){
		//If the block has non valid lru update the lruChecker and block. 
		if(blocks[i].getLru() == -1){
			//Goes through each of the blocks.
			for(int j = 0; j < numBlocks; j++){
				//If the block has a valid lru
				if(blocks[j].getLru() > -1){
					//Set that block lru value using the lruChecker
					blocks[j].setLru(lruChecker); 
				}
			}
			//Update the block with the tag, 0 for lru, and true for valid bit. 
			blocks[i].update(tag,0,true); 
			//increment lruChecker. 
			lruChecker++; 
			//Mod the lruChecker so that it remains within the number of blocks range. 
			lruChecker = lruChecker%numBlocks; 
			//return false that it was a miss. 
			return false; 
		}
	}
	//Otherwise a miss occured. 
	//Updates the cache if its a miss. 
	//return false. 	
	updateLruMiss(tag); 
	return false; 
}


/*
 * This helper method uses the highest lru in the set's block or blocks. 
 * Then returns using the block array the index or block that contains the highest lru. 
 * This is used to figure out which block index is updated in the set. 
 */
int Set::findHighestLru(){
	//Used for tmp   
	int tmp = -1; 
	//Start index at 0. 
	int index = 0;  
	//Iterate through the blocks. 
	for(int i =0; i < numBlocks; i++){
		//Checks if the block is greater than previous.
		//If true, increment index by 1, then set tmp as the blocks lru. 
		if(tmp < blocks[i].getLru()){
			index++;   
			tmp = blocks[i].getLru(); 
		}
	}
	//Always decrement the index by one because it will always be one index greater than the one desired. 
	index--; 
	//return the index of the least recently used that we want to replace when we miss.  
	return index; 
}


/*
 * Helper method is used for when the Set has a hit in one of the blocks. 
 * The block number in the Set is passed in by using the index. You then update the rest of the lru's in the Set. 
 */
void Set::updateLruHit(int index){
	//Tmp used for the block lru value that we hit. 
	int tmp = blocks[index].getLru(); 
	
	//Increment through the blocks checking if the values do have a valid lru and that the block lru is less than the lru of the hit block. 
	for(int i = 0; i < numBlocks; i++){
		//If block has a valid lru and is less than hit block's lru increment the block's lru by one. 
		if((blocks[i].getLru() != -1) && (blocks[i].getLru() < tmp)){
			blocks[i].setLru(blocks[i].getLru()+1); 
	
		}
	}
	//Set the hit block lru to 0 because it is now the most recently used block in the Set. 
	blocks[index].setLru(0); 
}

/*
 * Helper method is used for when the Set has a miss after checking all its blocks using the tag we 
 * replace the block that has been used the least recently and then we must update the rest of the block's lru. 
 */
void Set::updateLruMiss(long long tag){
	//Get the block that has been used the least recently. 
	int index = findHighestLru(); 
			
	//Goes through each of the blocks and sets its new lru by adding it by one and modulating it by the num of blocks. 
	for(int k = 0; k < numBlocks; k++){
		blocks[k].setLru((((blocks[k].getLru())+1)%numBlocks)); 
	}
	//Updates the block with the least recently used lru and replaces it with new data.  
	blocks[index].update(tag,0,true); 
			
}


