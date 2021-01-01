#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // make dummy
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // make new node
	newNode->data = data;

	newNode->next = plist->head->next; // make new node point other node
	plist->head->next = newNode; // make dummy node point new node

	(plist->numOfData)++; 
}


void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL) // no sorting standard
		FInsert(plist, data); // insert at front of the list
	//else // if there is sorting standard
		//SInsert(plist, data); // insert data with standard
}

bool LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL) // there is no data
		return false;
	
	plist->before = plist->head; // before point dummy
	plist->cur = plist->head->next; // first node

	*pdata = plist->cur->data; // store first data at pdata
	return true;
}
bool LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) // there is no data
		return false;

	plist->before = plist->cur; // update before
	plist->cur = plist->cur->next; // update cur

	*pdata = plist->cur->data; // store next data at pdata
	return true;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur; // object that will be removed address
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next; // remove object from list
	plist->cur = plist->before; // update cur

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));