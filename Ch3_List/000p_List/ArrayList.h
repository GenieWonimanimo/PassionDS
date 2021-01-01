#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include <stdbool.h>

/*** Definition of ArrayList ****/
#define LIST_LEN	100
typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN]; // list storage
	int numOfData; // num of saved data
	int curPosition; // save data reference location
} ArrayList;


/*** operation relevant to ArrayList ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

bool LFirst(List * plist, LData * pdata); // ref first data
bool LNext(List * plist, LData * pdata); // ref data after second

LData LRemove(List * plist); // remove ref data
int LCount(List * plist); // return the num of saved data

#endif