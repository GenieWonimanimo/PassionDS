#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** Make and Init ArrayList ***/
	List list;
	int data;
	ListInit(&list);

	/*** save 5 data ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	/*** print all stored data ***/
	printf("The num of data: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // visit first data
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // visit after second
			printf("%d ", data);
	}
	printf("\n\n");

	/*** remove all 22 ***/
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	/*** print all data after removing ***/
	printf("The num of data: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}