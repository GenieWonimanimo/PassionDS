#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"

void QueueInit(Queue* pq)
{
	DequeInit(pq);
}

bool QIsEmpty(Queue* pq)
{
	return DQIsEmpty(pq);
}

void EnQueue(Queue* pq, Data data)
{
	DQAddLast(pq, data);
}

Data DeQueue(Queue* pq)
{
	return DQRemoveFirst(pq);
}

Data QPeek(Queue* pq)
{
	return DQGetFirst(pq);
}