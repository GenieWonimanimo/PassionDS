#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int expLen = strlen(exp);
	
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode(); // make new node

		if (isdigit(exp[i])) // exp[i] is operand
			SetData(pnode, exp[i] - '0');
		else // exp[i] is operator
		{
			SetData(pnode, exp[i]);
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack); // return root node
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // if leaf node(operand)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
		
	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9) // if data is operand
		printf("%d ", data);
	else // if data is operator
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

/*
void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}
*/
// using paren Infix(333p)
void ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL) // if bt is not leaf node(operand)
		printf("( ");

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL) // if bt is not leaf node(operand)
		printf(") ");
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}