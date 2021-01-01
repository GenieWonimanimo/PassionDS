#include <stdio.h>
#include <stdlib.h>
#include "CListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

bool SIsEmpty(Stack* pstack)
{
	if (LCount(pstack->plist) == 0)
		return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack)
{
	Data rdata;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	LFirst(pstack->plist, &rdata);
	LRemove(pstack->plist);
	return rdata;
}

Data SPeek(Stack* pstack)
{
	Data data;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	LFirst(pstack->plist, &data);
	return data;
}

void SDelete(Stack* pstack)
{
	while (!SIsEmpty(pstack))
		SPop(pstack);
	free(pstack->plist);
}