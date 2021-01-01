#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
	List NCList;
	NameCard* pnc;
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	ListInit(&NCList);
	
	// Insert 3 person
	LInsert(&NCList, MakeNameCard("Won", "010-1234-5678"));
	LInsert(&NCList, MakeNameCard("Lyn", "010-2345-6789"));
	LInsert(&NCList, MakeNameCard("Chul", "010-3456-7890"));

	// search person
	printf("Input name of person you want to find: ");
	scanf(" %s", name);
	if (LFirst(&NCList, &pnc))
	{
		if (NameCompare(pnc, name)) // first name is not name	
		{
			while (LNext(&NCList, &pnc))
			{
				if (!NameCompare(pnc, name)) // pnc's name is name
					break;
			}
		}
	}
	ShowNameCardInfo(pnc);

	// search person and change phonenum
	printf("Input name of person you want to change phonenum: ");
	scanf(" %s", name);
	printf("Input phonenum: ");
	scanf(" %s", phone);
	if (LFirst(&NCList, &pnc))
	{
		if (NameCompare(pnc, name)) // first name is not name
		{
			while (LNext(&NCList, &pnc))
			{
				if (!NameCompare(pnc, name)) // pnc's name is name
					break;
			}
		}
	}
	printf("Before change \n");
	ShowNameCardInfo(pnc);
	ChangePhoneNum(pnc, phone);
	printf("After change \n");
	ShowNameCardInfo(pnc);

	// search person and delete
	printf("Input name of person you want to delete: ");
	scanf(" %s", name);
	if (LFirst(&NCList, &pnc))
	{
		if (NameCompare(pnc, name)) // first name is not name
		{
			while (LNext(&NCList, &pnc))
			{
				if (!NameCompare(pnc, name)) // pnc's name is name
					break;
			}
		}
	}
	pnc = LRemove(&NCList);
	free(pnc);

	// print info of all person
	if (LFirst(&NCList, &pnc))
	{
		ShowNameCardInfo(pnc);
		while (LNext(&NCList, &pnc))
			ShowNameCardInfo(pnc);
	}
	return 0;
}