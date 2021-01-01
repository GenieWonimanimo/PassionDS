#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
	// make and init stack
	Stack stack;
	StackInit(&stack);

	// save data
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	// Pop and get data
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}