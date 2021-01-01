#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode; // only one difference with LInsertFront
	}

	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next; // connect new node and head node
		plist->tail->next = newNode; // connect new node and tail node
	}
	
	(plist->numOfData)++;
}

bool LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL) // empty
		return false;
	
	plist->before = plist->tail; // before point tail
	plist->cur = plist->tail->next; // cur point head

	*pdata = plist->cur->data;
	return true;
}

bool LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL) // empty
		return false;

	plist->before = plist->cur; // before point next of before
	plist->cur = plist->cur->next; // cur point next of cur

	*pdata = plist->cur->data;
	return true;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) // tail point the node that gonna be deleted
	{
		if (plist->tail == plist->tail->next) // last node
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}