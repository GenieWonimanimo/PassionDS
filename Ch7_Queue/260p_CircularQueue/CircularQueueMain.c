#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
	// make and init queue
	Queue q;
	QueueInit(&q);

	// EnQueue data
	EnQueue(&q, 1); EnQueue(&q, 2);
	EnQueue(&q, 3); EnQueue(&q, 4);
	EnQueue(&q, 5);

	// DeQueue data
	while (!QIsEmpty(&q))
		printf("%d ", DeQueue(&q));

	return 0;
}