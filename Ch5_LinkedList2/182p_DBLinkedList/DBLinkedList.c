#include <stdio.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// if first, plist->head == NULL
	newNode->next = plist->head;
	// only for add node at second~
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

bool LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return false;
	
	plist->cur = plist->head; // cur point first node
	*pdata = plist->cur->data;
	return true;
}

bool LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL) // cur is already last node
		return false;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return true;
}

bool LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL) // cur is already first node
		return false;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return true;
}

int LCount(List* plist)
{
	return plist->numOfData;
}