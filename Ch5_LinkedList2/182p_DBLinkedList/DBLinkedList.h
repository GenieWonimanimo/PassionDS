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
	Node* cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

bool LFirst(List* plist, Data* pdata);
bool LNext(List* plist, Data* pdata);
bool LPrevious(List* plist, Data* pdata);
int LCount(List* plist);

#endif