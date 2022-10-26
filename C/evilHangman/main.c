#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]) {
	int i = 0;
	MY_STRING hString[100];

	hString[i] = my_string_init_c_string("COPY ME!");
	i++;

	for (i; i < 100; i++) {
		hString[i] = my_string_init_default();
	}

	i = 0;

	print_string(hString[i]);

	if (hString[i] != NULL) {
		printf("String not destroyed!\n");
	}
	else {
		printf("String destroyed!\n");
	}

	//Testing out edited push_back function
	/*for (int i = 0; i < 5; i++) {
		my_string_push_back(hString, "COPY ME!");
	}*/

	for (int i = 1; i < 100; i++) {
		my_string_assignmment(&hString[0], hString[i]);
	}
	
	for (int i = 0; i < 100; i++) {
		print_string(hString[i]);
		my_string_destroy(&hString[i]);
	}

	if (hString[0] != NULL) {
		printf("String not destroyed!\n");
	}
	else {
		printf("String successfully destroyed!\n");
	}

	return 0;
}