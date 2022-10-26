#include <stdio.h>
#include "status.h"
#include "generic.h"

typedef void* MY_STRING;

MY_STRING my_string_init_c_string(const char* c_string);

void print_string(MY_STRING hMy_string);

void my_string_destroy(Item* pItem);

int my_string_get_size(hMy_string);

int my_string_get_capacity(hMy_string);

void my_string_assignmment(Item* pLeft, Item Right);

char* my_string_c_str(MY_STRING hMy_string);

Status my_string_push_back(MY_STRING hMy_string, const char* c_string);

MY_STRING my_string_init_default(void);



void my_string_pop_back(MY_STRING hMy_string);

void my_string_at(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

Boolean my_string_empty(MY_STRING hMy_string);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);




