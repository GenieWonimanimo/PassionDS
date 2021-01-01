#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

bool DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return true;
	else
		return false;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;
	
	if (DQIsEmpty(pdeq)) // if deq is empty
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq)) // if deq is empty
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	Node* delNode;
	Data retData;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	// save info of node at front
	delNode = pdeq->head;
	retData = delNode->data;

	// disconnect delNode
	pdeq->head = pdeq->head->next;
	free(delNode);
	
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return retData;
	
}

Data DQRemoveLast(Deque* pdeq)
{
	Node* delNode;
	Data retData;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	// save info of node at tail
	delNode = pdeq->tail;
	retData = delNode->data;

	// disconnect delNode
	pdeq->tail = pdeq->tail->prev;
	free(delNode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return retData;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;
}
Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}