/*	Alex Baboshin, AxFisr@gmail.com
	Memory allocation and management
	MemoryHead.h  */

#ifndef _MemoryHead        //if not define
#define _MemoryHead
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


// Declaration of functions
int MemoryInit(int num_of_blocks, int block_size);
int* MyMalloc();
void MyFree(int* block);

// Global variable
int *p_Memory_blocks;

#endif