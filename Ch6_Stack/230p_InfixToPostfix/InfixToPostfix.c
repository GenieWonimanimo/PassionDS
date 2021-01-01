#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1; // lowest prec
	default:
		return -1; // unregistered
	}
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) // op1 has higher prec
		return 1;
	else if (op1Prec < op2Prec) // op2 has higher prec
		return -1;
	else // op1 and op2 has equal prec
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, expLen + 1); // init bytes that allocated for convExp as 0
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		// save each char in exp at tok
		tok = exp[i];
		if (isdigit(tok)) // if tok is digit, save
			convExp[idx++] = tok;
		else // tok is not digit(tok is operator)
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok); // open parenthesis, push
				break;
			case ')':
				while (1)
				{
					popOp = SPop(&stack); // pop operator from stack
					if (popOp == '(') // while popOp is not '('
						break;
					convExp[idx++] = popOp; // save
				}
				break;
			case '+': case '-':
			case '*': case '/':
				// stack is not empty && operator at top of the stack has higher prec than tok
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack); // pop and save
				SPush(&stack, tok);
				break;
			}
		}
	}

	// save all remain operator 
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}