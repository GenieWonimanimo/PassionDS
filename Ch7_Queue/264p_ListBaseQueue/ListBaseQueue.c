#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

bool QIsEmpty(Queue* pq)
{
	if (pq->front == NULL) // if queue is empty
		return true;
	else
		return false;
}

void EnQueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) // first time for Enqueue
	{
		// make front and rear point new node
		pq->front = newNode;
		pq->rear = newNode;
	}
	else // already queue has a node other than new node
	{
		pq->rear->next = newNode; // make last node point new node
		pq->rear = newNode; // and rear point new node
	}
}

Data DeQueue(Queue* pq)
{
	Node* delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	// save info of node at front
	delNode = pq->front;
	retData = delNode->data;
	// make front point next of the del node
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}