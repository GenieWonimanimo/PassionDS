#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#define _CRT_SECURE_NO_WARNINGS

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// dynamic alloc, init and return address of NameCard var
NameCard* MakeNameCard(const char* name, const char* phone);

// print info of NameCard var
void ShowNameCardInfo(NameCard* pcard);

// return 0 if same, else then return not 0
int NameCompare(NameCard* pcard, const char* name);

// change phone info
void ChangePhoneNum(NameCard* pcard, const char* phone);

#endif