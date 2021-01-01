#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(const char* name, const char* phone)
{
	NameCard* namecard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(namecard->name, name);
	strcpy(namecard->phone, phone);
	return namecard;
}

void ShowNameCardInfo(NameCard* pcard)
{
	printf("name: %s\n", pcard->name);
	printf("phone: %s\n", pcard->phone);
}

int NameCompare(NameCard* pcard, const char* name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard* pcard, const char* phone)
{
	strcpy(pcard->phone, phone);
}