#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#include <stdbool.h>

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue
{
	Node* front;
	Node* rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
bool QIsEmpty(Queue* pq); // return true if queue is empty

void EnQueue(Queue* pq, Data data); // EnQueue at the rear
Data DeQueue(Queue* pq); // DeQueue from the rear
Data QPeek(Queue* pq); // Get Data from the rear

#endif