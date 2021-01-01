#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*"; // postfix
	BTreeNode* eTree = MakeExpTree(exp);

	printf("Prefix expression: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("Infix expression: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("Postfix expression: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("result: %d \n", EvaluateExpTree(eTree));

	return 0;
}