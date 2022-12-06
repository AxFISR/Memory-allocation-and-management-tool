/*	Alex Baboshin, AxFisr@gmail.com 
	Memory allocation and management  
	MemoryMain.c  */

#include "MemoryHead.h"


int main() {
	//local variables
	int num_of_blocks, blocks_size, user_option,*user_block=0,*temp_free_block=NULL;

	//user interface
	printf("Memory allocation and management\n>>Enter number of blocks: ");
	if (!scanf("%d", &num_of_blocks)) {
		printf("\nError: reading input(num_of_blocks)"); return 1;
	}

	printf("\n>>Enter blocks size(bytes): ");
	if (!scanf("%d", &blocks_size)) {
		printf("\nError: reading input(blocks_size)"); return 1;
	}

	//Initialization process ,returns 1 if fails
	if (MemoryInit(num_of_blocks, blocks_size)) {
		printf("\nError: Initialization did not work"); return 1;
	}
	temp_free_block = p_Memory_blocks;
	//user management options
	printf("\n>>Enter '1' to receive available memory block\n>>Enter '2' to free last block that used\n>>Enter '0' to exit the program\n");
	if (!scanf("%d", &user_option)) {
		printf("\nError: reading input(user_option)"); return 1;
	}

	while (user_option) {
		switch (user_option)
		{
		case 1:
		{
			user_block = MyMalloc();
			break;
		}
		case 2:
		{
			MyFree(user_block);
			break;
		}
		default:
			break;
		}

		printf("\n>>Enter '1' to receive available memory block\n>>Enter '2' to free last block that used\n>>Enter '0' to exit the program\n");
		if (!scanf("%d", &user_option)) {
			printf("Error: reading input(user_option)"); return 1;
		}

	}
	//after returning all the used blocks
	//free(temp_free_block);
	
	return 0;
}