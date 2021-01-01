#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

int main(void)
{
	List empList;
	Employee* pEmp;
	char empName[10];
	int dayAfter;
	int i = 0;
	ListInit(&empList);

	// Insert 4 emp in the list
	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "Won");
	pEmp->ID = 1;
	LInsert(&empList, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "Lyn");
	pEmp->ID = 2;
	LInsert(&empList, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "Ok");
	pEmp->ID = 3;
	LInsert(&empList, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "Chul");
	pEmp->ID = 4;
	LInsert(&empList, pEmp);

	// find on-call after (dayAfter) day
	printf("Name: "); scanf(" %s", empName);
	printf("Being on watch after: "); scanf(" %d", &dayAfter);
	if (LFirst(&empList, &pEmp)) // list is not empty
	{
		if (strcmp(empName, pEmp->name)) // not match with first node
		{
			for (i = 0; i < LCount(&empList) - 1; i++)
			{
				LNext(&empList, &pEmp);
				if (!strcmp(empName, pEmp->name)) // find!
					break;
			}
		}
	}

	if (i < LCount(&empList) - 1) // find
	{
		// the day after
		for (i = 0; i < dayAfter; i++)
			LNext(&empList, &pEmp);

		printf("On-call is\n");
		ShowEmployeeInfo(pEmp);
	}
	else
		printf("Can't find\n");
	
	return 0;
}