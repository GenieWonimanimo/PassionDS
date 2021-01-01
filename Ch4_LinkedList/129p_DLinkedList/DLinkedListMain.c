#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// make and init list
	List list;
	int data;
	ListInit(&list);

	// save 5 data
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

	// print all remain data
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