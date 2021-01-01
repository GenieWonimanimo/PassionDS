#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0; // there is no saved data
	(plist->curPosition) = -1; // ref nothing
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData >= LIST_LEN) // if there is no space to insert
	{
		puts("can't save.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

bool LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) // if there is no saved data
		return false;

	(plist->curPosition) = 0; // init ref location, ref first data
	*pdata = plist->arr[0]; // save data to space that pointed by pdata
	return true;
}

bool LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1) // if there is no more data to ref
		return false;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return true;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition; // position to remove
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos]; // gonna be removed data

	// data move for removing
	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata; // return removed data
}

int LCount(List * plist)
{
	return plist->numOfData;
}