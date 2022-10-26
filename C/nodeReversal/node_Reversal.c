/**********************************************************************
Program: Node list reversal
Author: Daniel De Luna
Date: 09/28/2020
Time spent: 50 mins
Purpose: The purpose of this program is to reverse the created "test list" with the help of nodes. 
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
Node* reverse_node(Node* head);


int main(int argc, char* argv[])
{
	Node* head = NULL;
	Node* temp;
	int i;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}
	//Prints list.
	printf("Your node list is\n");
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	//call your function to reverse the list (should work for any list given the head node).
	head = reverse_node(head);

	//Prints the reversed list.
	printf("Your reversed node list is\n");
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	free(temp);
	return 0;
}

//Define your function here
Node* reverse_node(Node* head) {
	Node* reverse = (Node*)head;
	Node* tail = NULL;
	Node* temp = NULL;
	if (reverse != NULL) {
		for (int i = 0; i < 10; i++) {
			temp = reverse->next;
			reverse->next = tail;
			tail = reverse;
			reverse = temp;
		}
	}
	return tail;
}