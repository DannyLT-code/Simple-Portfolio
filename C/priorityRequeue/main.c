#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int main(int argc, char* argv[]) {
	PRIORITY_QUEUE phQueue = NULL;
	Status status = SUCCESS;
	phQueue = priority_queue_init_default();

	if (priority_queue_is_empty(phQueue) == TRUE) {
		printf("It is empty!\n");
	}

	status = priority_queue_insert(phQueue, 1, 0);
	if (priority_queue_is_empty(phQueue) == FALSE) {
		printf("It is not empty!\n");
	}
	//Priority is the first value, the second value is the data being stored.
	status = priority_queue_insert(phQueue, 2, 5);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_insert(phQueue, 3, 2);
	status = priority_queue_insert(phQueue, 4, 1);
	status = priority_queue_insert(phQueue, 5, 8);
	status = priority_queue_insert(phQueue, 6, 3);
	status = priority_queue_insert(phQueue, 7, 7);
	status = priority_queue_insert(phQueue, 8, 4);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_insert(phQueue, 9, 6);
	status = priority_queue_insert(phQueue, 0, 9);

	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));

	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	status = priority_queue_service(phQueue);
	printf("The data value for the highest priority item in the queue is %d \n", priority_queue_front(phQueue, &status));
	
	priority_queue_destroy(&phQueue);

	return 0;
}



