#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
	List list;
	Data data;
	ListInit(&list);

	// save 8 data
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// visit saved data
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
	}

	// remove multiplies of 2
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// revisit saved data
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
	}

	// reversely visit saved data
	while (LPrevious(&list, &data))
		printf("%d ", data);
	printf("\n\n");
	return 0;
}