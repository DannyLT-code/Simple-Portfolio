/***********************************************************
Author: Daniel De Luna
Date: 10/05/2020
Effort: 2:30 hours
Purpose: The purpose of this program is to implement all of our previous Daily's (With the exception of daily 6) 
Into one single program that works with Vector-like objects, dynamic memory allocation and different header files.
 Interface proposal: I added my own print display function to facilitate how the bits are printed onto the screen.
 However, I believe a function similar to the one in Daily 5 where 2 functions do the job would help thanks to the fact that 
 our flag position works like the index of an array of bits that we have access to set and
 unset at will. 
 Not just this but other functions such as one which returns a Boolean could help us verify whether our handles are valid (or not) 
 and would further help our code to become a lot more efficient (Less repeated lines).
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

//my_bits object
struct my_bits {
	int size;
	int capacity;
	int* data;
};

typedef struct my_bits myBits;

//Initializes BIT_FLAGS object with a set number of bits 
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
	myBits* pBits = NULL;
	pBits = (myBits*)malloc(sizeof(myBits));
	int x = number_of_bits;
	//Verifies that number_of_bits is a positive integer.
	//If not it asks for user to input a new VALID number of bits.
	while (x < 0) {
		printf("Error, Invalid number_of_bits, number_of_bits has to be positive!\n");
		printf("Please input a valid number of bits: ");
		scanf("%d", &x);
	}
	//Verifies that dynamic memory was succesfully allocated.
	if (pBits != NULL) {
		//Default size of my_bits object (32 bits).
		pBits->size = 32;
		//Capacity set by user.
		pBits->capacity = x;
		//As long as Capacity set by user is bigger than default size it expands.
		while (x >= pBits->size) {
			pBits->size = pBits->size + 32;
		}
		//Dynamically allocates memory for my_string data.
		pBits->data = (int*)malloc(sizeof(int) * pBits->size);
		//if NULL frees up previously allocated memory and exits function.
		if (pBits->data == NULL) {
			printf("Error allocating memory, please try again\n");
			free(pBits);
			return NULL;
		}
		//Initilizes our data array to 0.
		for (int i = 0; i < pBits->size; i++) {
			pBits->data[i] = 0;
		}
	}
	//If everything is successful returns the handle to our BIT_FLAGS object.
	return pBits;
}

//Sets specified flags 
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {
	myBits* pBits = (myBits*)hBit_flags;
	int x = flag_position;
	int* temp = NULL;
	//Verifies valid handle to BIT_FLAGS object
	if (pBits != NULL) {
		//Verifies that flag_position is a positive integer.
		//If not it asks for user to input a new VALID flag position. 
		while (x < 0) {
			printf("Error, Invalid flag_position, flag_position has to be positive!\n");
			printf("Please input a valid flag position: ");
			scanf("%d", &x);
		}
		//As long as the flag position is greater than our structure's size it will allocate more memory for it. 
		while ((x) >= pBits->size) {
			temp = (int*)malloc(sizeof(int) * pBits->size + 32);
			//if resize is unsuccessful it returns FAILURE.
			if (temp == NULL) {
				return FAILURE;
			}
			//Moves all of our data so nothing is lost during the re-sizing.
			for (int i = 0; i < pBits->capacity; i++) {
				temp[i] = pBits->data[i];
			}
			free(pBits->data);
			pBits->data = temp;
			pBits->size = pBits->size + 32;
		}
		//1 is moved to the left the number of bits specified by the right operand "x" (flag_position). 
		//Afterwards it is compared to our handle and copies a bit if it exists in either operand ensuring all bits remain. 
		pBits->data[x / 32] = pBits->data[x / 32] | 1 << x;
		return SUCCESS;
	}
	//If invalid BIT_FLAGS handle it returns failure.
	return FAILURE;
}

//Unsets specified flags
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
	myBits* pBits = (myBits*)hBit_flags;
	int x = flag_position;
	int* temp = NULL;
	//Verifies valid handle to BIT_FLAGS object
	if (pBits != NULL) {
		//Verifies that flag_position is a positive integer.
		//If not it asks for user to input a new VALID flag position. 
		while (x < 0) {
			printf("Error, Invalid flag_position, flag_position has to be positive!\n");
			printf("Please input a valid flag position: ");
			scanf("%d", &x);
		}
		//As long as the flag position is greater than our structure's size it will allocate more memory for it. 
		while ((x) >= pBits->size) {
			temp = (int*)malloc(sizeof(int) * pBits->size + 32);
			//if resize is unsuccessful it returns FAILURE.
			if (temp == NULL) {
				return FAILURE;
			}
			//Moves all of our data so nothing is lost during the re-sizing.
			for (int i = 0; i < pBits->capacity; i++) {
				temp[i] = pBits->data[i];
			}
			free(pBits->data);
			pBits->data = temp;
			pBits->size = pBits->size + 32;
		}
		//1 is moved to the left the number of bits specified by the right operand "x" (flag_position).
		//Afterwards the bits are flipped and then compared to our handle. If a bit exists in both it remains, if not it copies a 0.
		pBits->data[x / 32] = pBits->data[x / 32] & ~(1 << x);
		return SUCCESS;
	}
	return FAILURE;
}

//Checks which flags have been set. 
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
	myBits* pBits = (myBits*)hBit_flags;
	int x = flag_position;
	//Verifies valid handle to BIT_FLAGS object
	if (pBits != NULL) {
		//If the flag position is greater than our capacity (i.e If we requested only 5 bits during our
		//initilization and our flag position is at 6)
		//It will return a -1 to symbolize it is out of bounds.
		if (x > pBits->capacity) {
			return -1;
		}
		//If the flag is on (set) it will return a 1.
		else if ((pBits->data[x / 32] & 1 << x) != 0) {
			return 1;
		}
		//If the flag is off (unset) it will return a 0.
		else {
			return 0;
		}
	}
}

//Checks for size of my_string structure.
int bit_flags_get_size(BIT_FLAGS hBit_flags) {
	myBits* pBits = (myBits*)hBit_flags;
	if (pBits != NULL) {
		return pBits->size;
	}
}

//Checks for capacity of my_string structure.
int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
	myBits* pBits = (myBits*)hBit_flags;
	if (pBits != NULL) {
		return pBits->capacity;
	}
}

//Frees up all allocated memory.
void bit_flags_destroy(BIT_FLAGS* phBit_flags) {
	myBits* pBits = (myBits*)phBit_flags;
	free(pBits->data);
	free(pBits);
	*phBit_flags = NULL;
}

//Display_32_flags_as_array definition
void display_32_flags_as_array(BIT_FLAGS hBit_flags) {
	myBits* pBits = (myBits*)hBit_flags;
	if (pBits != NULL) {
		//For loop was modified to work with our array.
		for (int i = bit_flags_get_size(pBits) - 1; i >= 0; i--) {
			//Checks for a 1 or 0 bit and prints it.
			printf("%d", bit_flags_check_flag(pBits, i));
			//Every 4 bits a space is printed.
			if (i % 4 == 0) {
				printf(" ");
			}
			//Every 32 bits a new-line is printed.
			if (i % 32 == 0) {
				printf("\n");
			}
		}
	}
}
//

//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object.
//Postcondition: The flag at the flag_position index is set to 0. Function will attempt to resize the
// internal representation if the flag_position is too large instead of failing for out of bounds. Returns
// SUCCESS if the operation is successful and FAILURE if the operation fails a needed resize. This
// operation is considered to be expensive if flag_position is constantly going out of bounds by a small
// amount because the resize always attempts to minimize the amount of space required to store the bits.
// All new flags created in a resize operation will be set as zero.
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);

//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object.
//Postcondition: returns the value of the flag at index flag_position if it is in bounds or -1 otherwise.
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);

//Precondition: hBit_flags is a handle to a valid Bit_flags object.
//Postcondition: returns the number of bits currently held by the data structure.
int bit_flags_get_size(BIT_FLAGS hBit_flags);

//Precondition: hBit_flags is a handle to a valid Bit_flags object.
//Postcondition: returns the number of bits the object CAN hold.
int bit_flags_get_capacity(BIT_FLAGS hBit_flags);

//Precondition: phBit_flags is the address of a handle to a valid Bit_flags object.
//Postcondition: The memory for the object referred to by the handle is free'd and the handle is set to NULL.
void bit_flags_destroy(BIT_FLAGS* phBit_flags);

//Precondition: phBit_flags is the address of a handle to a valid Bit_flags object.
//Postcondition: Prints all flags depending on their value and whether they are in bounds or out of bounds.
void display_32_flags_as_array(BIT_FLAGS hBit_flags);

//Intentionally leaving out a default init function to force user to at least guess at the size needed.
//If one WERE to be used it would have the following prototype:
//BIT_FLAGS bit_flags_init_default(void);
//Precondition: number of bits is a positive integer.
//Postcondition: Returns the handle to a valid Bit_flags object that has the ability to store up to
// number_of_bits bits but currently all flags are set at zero. Returns NULL on failure. The container
// is assumed to hold size=number_of_bits after the init function runs.
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);

//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object.
//Postcondition: The flag at the flag_position index is set to 1. Function will attempt to resize the
// internal representation if the flag_position is too large instead of failing for out of bounds. Returns
// SUCCESS if the operation is successful and FAILURE if the operation fails a needed resize. This
// operation is considered to be expensive if flag_position is constantly going out of bounds by a small
// amount because the resize always attempts to minimize the amount of space required to store the bits.
// All new flags created in a resize operation (except the one being set) will be set as zero.
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);

#endif

//

int x = 0;
	BIT_FLAGS bit_flags = bit_flags_init_number_of_bits(x);
	bit_flags_set_flag(bit_flags, 16);
	bit_flags_set_flag(bit_flags, 31);
	bit_flags_set_flag(bit_flags, 32);
	bit_flags_unset_flag(bit_flags, 0);
	display_32_flags_as_array(bit_flags);
	bit_flags_destroy(bit_flags);
