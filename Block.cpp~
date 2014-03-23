#include "Block.h"

/*
 *Default constructor inits attributes of the class to default values. 
 */
Block::Block(){
	tag = 0; 
	index = -1; 
	lru = -1; 
	validBit = 0; 
}

/*
 *Deconstructor for Block class. 
 */
Block::~Block(){}
 
/*
 *Mutator method for setting the tag in Block. 
 */
void Block::setTag(long long tagBits){
	tag = tagBits; 
}

/*
 *Mutator method for setting the index in Block. 
 */
void Block::setIndex(int i){
	index = i; 
}

/*
 *Mutator method for setting the lru in a Block. 
 */
void Block::setLru(long long val){
	lru = val; 
}

/*
 *Method used to update the content of the Block in the Set regarding
 *its tag, lru, and valid bit information. 
 */
void Block::update(long long tagBit, long long lruBit, bool valid){
	tag = tagBit; 
	validBit = valid;
	lru = lruBit;  
	
}
