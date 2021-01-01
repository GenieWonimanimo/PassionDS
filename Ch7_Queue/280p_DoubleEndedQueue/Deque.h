#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stdbool.h>

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _dlDeque
{
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);
bool DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data); // add data at the head
void DQAddLast(Deque* pdeq, Data data); // add data at the tail

Data DQRemoveFirst(Deque* pdeq); // delete data at head
Data DQRemoveLast(Deque* pdeq); // delete data at tail

Data DQGetFirst(Deque* pdeq); // Get data at head
Data DQGetLast(Deque* pdeq); // Get data at tail

#endif