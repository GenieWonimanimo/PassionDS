#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#include <stdbool.h>

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _DBLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

// Init the list
void ListInit(List* plist);
// Insert node at head
void LInsert(List* plist, Data data);

bool LFirst(List* plist, Data* pdata);
bool LNext(List* plist, Data* pdata);
bool LPrevious(List* plist, Data* pdata);

// Remove node that cur is pointing
Data LRemove(List* plist);
// return numOfData
int LCount(List* plist);

#endif