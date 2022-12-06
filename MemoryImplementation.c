/*	Alex Baboshin, AxFisr@gmail.com
	Memory allocation and management
	MemoryImplementation.c  */

#include "MemoryHead.h"


//creating a memory pool of fixed sized blocks ,each block start will store the address of next block 
//as its value like linked list this is possible because block_size >= 4 bytes which can store address on a x86 machine
int MemoryInit(int num_of_blocks, int block_size) {

	//malloc the total memory pool size
	if ((p_Memory_blocks = (int*)malloc(sizeof(char) * num_of_blocks * block_size)) == NULL) {
		return 1;
	}
	//first 4 bytes of each block will store the address of next block (last block will point to NULL)
	for (int i = 0; i < num_of_blocks * block_size; i += block_size) {
		*(p_Memory_blocks + i) = (p_Memory_blocks + i + block_size);
		if(i+block_size == num_of_blocks * block_size)
			*(p_Memory_blocks + i) = NULL;
		
	}
	return 0;
}

//when block is needed , the pointer will advance to the address hes storing and return the previous block
int* MyMalloc() {
	int* return_block = p_Memory_blocks;

	//when no more blocks available
	if (p_Memory_blocks == NULL) {
		printf("No more available blocks");
	}
	//when its the last block available
	else if (*p_Memory_blocks == NULL) {
		p_Memory_blocks = NULL;
	}
	//when there is blocks available
	else if (*p_Memory_blocks != NULL) {
		p_Memory_blocks = (int*)(*p_Memory_blocks);
	}
	return return_block;
}

//MyFree will add the allocated block be the new "head" like linked list, can be used again next MyMalloc call
void MyFree(int* block) {
	*block = p_Memory_blocks;
	p_Memory_blocks = block;
}
