#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include <stdbool.h>

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList
{
	Node* head; // point dummy
	Node* cur; // for ref and remove
	Node* before; // for remove
	int numOfData;
	int (*comp)(LData d1, LData d2); // standard of sort
} LinkedList;
typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

bool LFirst(List* plist, LData* pdata);
bool LNext(List* plist, LData* pdata);

LData LRemove(List* plist); // cannot call successively
int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif