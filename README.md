# Memory-allocation-and-management-tool
/*	Alex Baboshin, AxFisr@gmail.com
	Memory allocation and management */

The mechanism allows the user to determine the amount and size of blocks needed for his program, 
and the mechanism performs the memory management process for the user. 
The size of each block is fixed and the same for each block.

Written and compiled on Visual Studio 2022 using x86 - 32bit machine (storing address inside 4byte memory wont be possible on 64bit machine)

For this memory pool manager the file MemoryMain.c is for personal use and testing , it isnt necessary for the program to run.

Furthermore its even better you wont use this file because it might generate bugs like memory heap corruption when trying to free allocated memory.

Memory size allocation tested using Visual Studio 2022 built in 'Memory Usage' feature that takes snapshots of current allocated memory on Windows 11,
also the correctness of allocating specific amount of bytes tested inside a virtual machine (Oracle VM) on CentOS2020 linux operation system and yielded the same results.
