#include <stdio.h>
#include "Deque.h"

int main(void)
{
	// make and init deque
	Deque deq;
	DequeInit(&deq);

	// save data
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// get data
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	printf("\n");

	// save data
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// get data
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	return 0;
}