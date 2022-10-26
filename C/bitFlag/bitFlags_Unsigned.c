/***********************************************************
Author: Daniel De Luna
Date: 09/21/2020
Effort: 30 minutes
Purpose: The purpose of this assignment was to simplify our previous code by turning a few lines of code into functions
while adding a new function that can unset previously set flags. All function parameters have also been updated to work with unsigned integers. 
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[]) {
	unsigned int flag_holder = 0;
	//Sets 3 flags in our 32 bit holder (3, 16, 31).
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	//Prints all 32 flags.
	display_32_flags(flag_holder);
	//Unsets 2 of the flags that were previously set (31, 3).
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	//Sets a new flag in the 9th position.
	set_flag(&flag_holder, 9);
	//Prints all 32 updated flags. 
	display_32_flags(flag_holder);
	return 0;
}
//Set_flag definition.
void set_flag(unsigned int* flag_holder, int flag_position) {
	//1 is moved to the left the number of bits specified by the right operand "flag_position". 
	//Afterwards it is compared to *flag_holder and copies a bit if it exists in either operand ensuring all bits remain.
	*flag_holder = *flag_holder | 1 << flag_position;
}
//Check_flag definition. 
int check_flag(unsigned int flag_holder, int flag_position) {
	int x; 
	//flag_holder is moved to the right the number of bits specified by the right operand "flag_position". 
	//Afterwards it is compared to 1 and returns a bit to the result if it exists in both operands, if not it returns a 0.
	x = (flag_holder >> flag_position) & 1;
	return x;
}

void display_32_flags(unsigned int flag_holder) {
	for (int i = 31; i >= 0; i--)
	{
		//Checks for a 1 or 0 bit and prints it. 
		printf("%d", check_flag(flag_holder, i));
		//Every 4 bits a space is printed. 
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void unset_flag(unsigned int* flag_holder, int flag_position) {
	//1 is moved to the left the number of bits specified by the right operand "flag_position".
	//Afterwards the bits are flipped and then compared to *flag_holder. If a bit exists in both it remains, if not it copies a 0. 
	*flag_holder = *flag_holder & ~(1 << flag_position);
}
