#ifndef __DQ_BASE_QUEUE_H__
#define __DQ_BASE_QUEUE_H__

#include <stdbool.h>
#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue* pq);
bool QIsEmpty(Queue* pq);

void EnQueue(Queue* pq, Data data);
Data DeQueue(Queue* pq);
Data QPeek(Queue* pq);

#endif