#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include <stdbool.h>

/*** Definition of ArrayList ****/
#define LIST_LEN	100
typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** operation relevant to ArrayList ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

bool LFirst(List * plist, LData * pdata);
bool LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif