#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)
{
	// if queue is empty, front and rear is same
	pq->front = 0;
	pq->rear = 0;
}

// for cycle front and rear
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1) // if pos is index of last elements of array
		return 0;
	else
		return pos + 1;
}

bool QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear) // if queue is empty
		return true;
	else
		return false;
}

bool QIsFull(Queue* pq)
{
	if (NextPosIdx(pq->rear) == pq->front) // if queue is full
		return true;
	else
		return false;
}

void EnQueue(Queue* pq, Data data)
{
	if (QIsFull(pq)) // if queue is full
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}