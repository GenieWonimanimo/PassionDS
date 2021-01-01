#include <stdio.h>
#include "DBDLinkedList.h"

void ListInit(List* plist)
{
	// make head point to dummy node
	plist->head = (Node*)malloc(sizeof(Node));
	// make tail point to dummy node
	plist->tail = (Node*)malloc(sizeof(Node));

	// connect two dummy
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	// make new node and save data at new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	/* 
	// insert at head
	// link new node and existing node
	plist->head->next->prev = newNode;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	newNode->prev = plist->head;
	*/
	// insert at tail
	// link new node and existing node
	plist->tail->prev->next = newNode;
	newNode->prev = plist->tail->prev;
	plist->tail->prev = newNode;
	newNode->next = plist->tail;
	
	(plist->numOfData)++;
}

bool LFirst(List* plist, Data* pdata)
{
	// list is empty
	if (plist->head->next == plist->tail)
		return false;
	
	plist->cur = plist->head->next; // cur point first node (head is dummy node)
	*pdata = plist->cur->data;
	return true;
}

bool LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == plist->tail) // cur is already last node
		return false;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return true;
}

bool LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == plist->head) // cur is already first node
		return false;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return true;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = plist->cur->data;

	// remove cur
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	// update cur
	plist->cur = plist->cur->prev;

	free(rpos);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}