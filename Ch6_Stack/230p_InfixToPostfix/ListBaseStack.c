#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	// Init head as NULL
	pstack->head = NULL;
}

bool SIsEmpty(Stack* pstack)
{
	// if stack is empty
	if (pstack->head == NULL)
		return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	// make new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	// new node point recently added node
	newNode->next = pstack->head;

	// new node is recently added node from now
	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memoty Error!");
		exit(-1);
	}

	// save info of the node that will be deleted
	rdata = pstack->head->data;
	rnode = pstack->head;

	// remove head node(recently added node) from the stack
	pstack->head = pstack->head->next;
	free(rnode);
	return rdata; // return data of removed node
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data; // return data of head node
}