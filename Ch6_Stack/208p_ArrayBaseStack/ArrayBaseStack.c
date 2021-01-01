#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

bool SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	// increase topIndex for push data at proper location
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	// if stack is empty
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	// save index that will be deleted
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1; // by pop, decrease topIndex

	return pstack->stackArr[rIdx]; // return deleted data
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	// return data at top
	return pstack->stackArr[pstack->topIndex];
}