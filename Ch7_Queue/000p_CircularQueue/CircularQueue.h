#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#include <stdbool.h>

#define QUE_LEN		100
typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq); // Init queue
bool QIsEmpty(Queue* pq); // return true if queue is empty
bool QIsFull(Queue* pq); // return true if queue is full

void EnQueue(Queue* pq, Data data); // Enqueue data at the rear
Data DeQueue(Queue* pq); // Dequeue data from the front
Data QPeek(Queue* pq); // Peek data at the front

#endif