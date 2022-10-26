#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct queue {
	int data;
	int priority;
	struct Queue* next;
};

typedef struct queue Queue;

struct heap {
	Queue* head;
};

typedef struct heap Heap;


PRIORITY_QUEUE priority_queue_init_default(void) {
	Heap* pQueue = NULL;
	pQueue = (Heap*)malloc(sizeof(Heap));
	if (pQueue != NULL) {
		pQueue->head = NULL;
		return pQueue;
	}
	else {
		printf("Error allocating memory!\n");
		free(pQueue);
		pQueue = NULL;
	}
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {
	Heap* pQueue = (Heap*)hQueue;
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	if (tmp == NULL) {
		printf("Error allocating memory!\n");
		return FAILURE;
	}
	if (pQueue != NULL) {
		tmp->data = data_item;
		tmp->priority = priority_level;
		tmp->next = pQueue->head;
		pQueue->head = tmp;
		return SUCCESS;
	}
	return FAILURE;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue) {
	int priority = 0, count = 0, nodeToDelete = 0;
	Heap* pQueue = (Heap*)hQueue;
	Queue* current = pQueue->head;
	Queue* previous = NULL;
	Queue* tmp;
	if (pQueue == NULL) {
		printf("Error\n");
		return FAILURE;
	}
	tmp = pQueue->head;
	while (tmp != NULL) {
		count++;
		if (tmp->priority >= priority) {
			priority = tmp->priority;
			nodeToDelete = count;
		}
		tmp = tmp->next;
	}
	while (current->priority != priority && pQueue->head != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	free(current);
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) {
	Heap* pQueue = (Heap*)hQueue;
	if (*pStatus == NULL) {
		printf("Ignored, address to pStatus was NULL\n");
		return;
	}
	else if (pQueue != NULL) {
		printf("Not ignored!\n");
		int priority = 0, count = 0, nodeToDelete = 0;
		Heap* pQueue = (Heap*)hQueue;
		Queue* current = pQueue->head;
		Queue* previous = NULL;
		Queue* tmp;
		if (pQueue == NULL) {
			return FAILURE;
		}
		tmp = pQueue->head;
		while (tmp != NULL) {
			count++;
			if (tmp->priority >= priority) {
				priority = tmp->priority;
				nodeToDelete = count;
			}
			tmp = tmp->next;
		}
		while (current->priority != priority) {
			previous = current;
			current = current->next;
		}
		return current->data;
	}
	return NULL;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {
	Heap* pQueue = (Heap*)hQueue;
	return (Boolean)(pQueue->head == NULL);
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) {
	Heap* pQueue = (Heap*)*phQueue;
	if (pQueue != NULL) {
		free(pQueue);
		*phQueue = NULL;
		printf("Queue successfully destroyed");
	}
}


// STUB FUNCTIONS
Boolean priority_queue_search(PRIORITY_QUEUE hQueue, int x) {
	Heap* current = (Heap*)hQueue; 
	while (current->head != NULL) {
		if (current->head->data == x)
			return TRUE;
		current->head = current->head->next;
	}
	return FALSE;
}

