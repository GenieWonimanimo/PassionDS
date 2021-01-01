#ifndef __C_LB_STACK_H__
#define __C_LB_STACK_H__

#include <stdbool.h>
#include "CLinkedList.h"

typedef struct _cListStack
{
	List* plist;
} CListStack;

typedef CListStack Stack;

// Init stack
void StackInit(Stack* pstack);
// return true if stack is empty
bool SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

void SDelete(Stack* pstack);

#endif