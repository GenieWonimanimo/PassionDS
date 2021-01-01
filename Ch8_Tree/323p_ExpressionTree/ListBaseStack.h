#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include <stdbool.h>
#include "BinaryTree.h"

typedef BTreeNode* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	Node* head;
} ListStack;

typedef ListStack Stack;

// Init stack
void StackInit(Stack* pstack);
// return true if stack is empty
bool SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif