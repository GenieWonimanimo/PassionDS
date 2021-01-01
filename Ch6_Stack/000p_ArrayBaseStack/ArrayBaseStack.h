#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#include <stdbool.h>
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

// Init stack
void StackInit(Stack* pstack);
// return true if stack is empty
bool SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif