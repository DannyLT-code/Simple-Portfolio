#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

struct my_string {
	int size;
	int capacity;
	char* data;
};

typedef struct my_string myString;

MY_STRING my_string_init_c_string(const char* c_string) {
	int counter;
	char x = ' ';
	myString* pString = NULL;
	pString = (myString*)malloc(sizeof(myString));
	if (pString == NULL) {
		printf("Error allocating memory\n");
		return NULL;
	}
	for (int i = 0; x != '\0'; i++) {
		x = c_string[i];
		counter = i;
	}
	pString->size = counter;
	pString->capacity = pString->size + 1;
	pString->data = (char*)malloc(sizeof(char) * pString->capacity);
	if (pString->data == NULL) {
		printf("Error allocating memory\n");
		free(pString);
		return NULL;
	}
	for (int i = 0; i < counter; i++) {
		pString->data[i] = c_string[i];
	}
	pString->data[counter] = '\0';
	return pString;
}

void print_string(MY_STRING hMy_string) {
	myString* pString = (myString*)hMy_string;
	int x = my_string_get_size(hMy_string);
	for (int i = 0; i < x; i++) {
		printf("%c", pString->data[i]);
	}
	printf("\n");
}

void my_string_destroy(Item* pItem) {
	myString* pString = (myString*)*pItem;
	free(pString->data);
	free(pString); 
	*pItem = NULL;
}

int my_string_get_size(hMy_string) {
	myString* pString = (myString*)hMy_string;
	if (pString == NULL) {
		printf("Error allocating memory\n");
		return 0;
	}
	return pString->size;
}

int my_string_get_capacity(hMy_string) {
	myString* pString = (myString*)hMy_string;
	if (pString == NULL) {
		printf("Error allocating memory\n");
		return 0;
	}
	return pString->capacity;
}

void my_string_assignmment(Item* pLeft, Item Right) {
	myString* pString_Left = (myString*)*pLeft;
	myString* pString_Right = (myString*)Right;
	char* temp;
	int counter = 0;
	if (pString_Right == NULL) {
		pString_Right = my_string_init_default();
	}
	if (pString_Left != NULL) {
		while (pString_Left->capacity > pString_Right->capacity) {
			temp = (char*)malloc(sizeof(char) * pString_Left->capacity);
			if (temp == NULL) {
				printf("Error allocating memory\n");
				return;
			}
			for (int i = 0; i < pString_Left->size; i++) {
				temp[i] = pString_Left->data[i];
				counter++;
			}
			temp[counter] = '\0';
			free(pString_Right->data);
			pString_Right->data = temp;
			pString_Right->capacity = pString_Left->capacity;
			pString_Right->size = pString_Left->size;
		}
	}
}

char* my_string_c_str(MY_STRING hMy_string) {
	myString* pString = (myString*)hMy_string;
	if (pString != NULL) {
		pString->data[pString->size] = '\0';
return &pString->data[0];
	}
	return NULL;
}

Status my_string_push_back(MY_STRING hMy_string, const char* c_string) {
	myString* pString = (myString*)hMy_string;
	char* temp;
	int counter, j;
	char x = ' ';
	for (int i = 0; x != '\0'; i++) {
		x = c_string[i];
		counter = i;
	}
	if (pString != NULL) {
		pString->size += counter;
		while (pString->size >= pString->capacity) {
			temp = (char*)malloc(sizeof(char) * (pString->capacity + counter + 1));
			if (temp == NULL) {
				return FAILURE;
			}
			for (j = 0; j < pString->capacity - 1; j++) {
				temp[j] = pString->data[j];
			}
			temp[j] = '\n';
			free(pString->data);
			pString->data = temp;
			pString->size = (pString->capacity + counter);
			pString->capacity = (pString->capacity + counter + 1);

			for (int i = 0; j < pString->size; i++) {
				pString->data[j + 1] = c_string[i];
				j++;
			}

		}
		//pString->data[pString->size] = '\0';
		return SUCCESS;
	}
	return FAILURE;
}

MY_STRING my_string_init_default(void) {
	myString* pString = NULL;
	pString = (myString*)malloc(sizeof(myString));
	int string_size = 5;
	if (pString != NULL) {
		pString->size = string_size;
		pString->capacity = string_size + 1;
		pString->data = (char*)malloc(sizeof(char) * pString->capacity);
		if (pString->data == NULL) {
			printf("Error allocating memory\n");
			free(pString);
			pString = NULL;
		}
	}
	return pString;
}


void my_string_pop_back(MY_STRING hMy_string) {
	;
}

void my_string_at(MY_STRING hMy_string) {
	;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
	;
}

Boolean my_string_empty(MY_STRING hMy_string) {
	;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
	;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
	myString* pString = (myString*)hMy_string;
	int string_size = pString->size;
	char ch;
	int counter = 0;
	if (pString != NULL) {
		if (fgetc(fp) == EOF) {
			return FAILURE;
		}
		fseek(fp, -1, SEEK_CUR);
		while (fscanf(fp, "%c", &ch) != EOF) {
			if (ch == ' ' && counter == string_size) {
				pString->data[counter] = '\0';
				fseek(fp, -1, SEEK_CUR);
				return SUCCESS;
			}
			else if (ch == '\n' && counter == string_size) {
				pString->data[counter] = '\0';
				fseek(fp, -1, SEEK_CUR);
				return SUCCESS;
			} 
			else if ((ch != ' ' || ch != '\n') && counter == string_size) {
				return FAILURE_NOT_EOF;
			}
			else if ((ch == ' ' || ch == '\n') && counter != string_size) {
				return FAILURE_NOT_EOF;
			}
			pString->data[counter] = ch;
			counter++;
		}
		pString->data[counter] = '\0';
		fseek(fp, -1, SEEK_CUR);
		return SUCCESS;
	}
	return FAILURE;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	int y = 0;
	char x = ' ';
	myString* string1 = (myString*)hLeft_string;
	myString* string2 = (myString*)hRight_string;
	if (string1 != NULL || string2 != NULL) {
		for (int i = 0; x != '\0'; i++) {
			if (string1->data[i] == string2->data[i]) {
				x = string1->data[i];
				y = 0;
			}
			else if (string1->data[i] == '\0' && string2->data[i] != '\0') {
				y = -1;
				return y;
			}
			else if (string1->data[i] != '\0' && string2->data[i] == '\0') {
				y = 1;
				return y;
			}
		}
	}
	return y;

}