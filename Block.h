#ifndef __BLOCK_H__
#define __BLOCK_H__
//Author: Nick Taylor

/*
 * The Block class is used to represent the blocks that within the Sets's in the Cache. 
 */
class Block{
	public:
		/*
 		 * Constructor for the Block class. 
 		 */ 
		Block(); 
		
		/*
 		 * Deconstructor for the Block class. 
 		 */
		~Block(); 

		/*
 		*Method that updates the Blocks in the Set with meta data 
		*such as the tag, lru, and valid bit. 
 		*/	 
		void update(long long tagBit, long long lruBit, bool valid);  
		
		/*
 		 *Returns the tag. 
 		 */ 
		long long getTag(){return tag;}; 
		/*
 		 *Returns the index. 
 		 */ 
		int getIndex(){return index;}; 
		
		/*
 		 *Returns the lru. 
 		 */ 
		long long getLru(){return lru;}; 
		/*
 		 * Returns the valid bit. 
 		 */ 
		bool getValidBit(){ return validBit;};
		
		/*
 		 *Sets the tag.
 		 */
		void setTag(long long tagBit); 
		/*
 		 *Sets the index. 
 		 */ 
		void setIndex(int i); 
		/*
 		 *Sets the lru
 		 */ 
		void setLru(long long val);   
	private:
		//Tag attribute. 
		long long tag; 
		//Index attribute. 
		int index; 
		//lru attribute. 
		long long lru; 
		//validBit attribute. 
		bool validBit; 
};
#endif
