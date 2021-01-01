#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// make and init DBLL
	List list;
	int data;
	ListInit(&list);

	// save 8 data
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// visit data
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// visit moving right
		while (LNext(&list, &data))
			printf("%d ", data);

		// visit moving left
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}
	return 0;
}