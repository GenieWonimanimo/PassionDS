#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#include <stdbool.h>

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;
typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); // Add node at tail
void LInsertFront(List* plist, Data data); // Add node at head

bool LFirst(List* plist, Data* pdata);
bool LNext(List* plist, Data* pdata);
Data LRemove(List* plist); // can call successively
int LCount(List* plist);

#endif
