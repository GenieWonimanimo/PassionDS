#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		// if tok is digit
		if (isdigit(tok))
			SPush(&stack, tok - '0');
		else // if tok is operator
		{
			op2 = SPop(&stack); // pop second operand from stack
			op1 = SPop(&stack); // pop first operand from stack
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);
}