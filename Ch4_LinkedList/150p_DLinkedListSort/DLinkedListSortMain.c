#include <stdio.h>
#include "DLinkedList.h"

// asecending order
bool WhoIsPrecede(int d1, int d2) // typedef int LData;
{
	if (d1 < d2)
		return false;
	else
		return true;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // set sort rule

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// print saved data
	printf("The number of data: %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// search 22 and remove
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// print remain data
	printf("The number of data: %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}