#include <stdio.h>
#include "arraylist.h"
#include "Namecard.h"

void ListInit(List *plist)
{
	(plist->numofData) = 0;
	(plist->curposition) = -1;
}

void LInsert(List *plist, Data data)
{
	if((plist->numofData) > LIST_LEN){
		puts("저장공간이 없습니다.");
		return;
	}
	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if(plist->numofData == 0)
		return FALSE;
	(plist->curposition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if(plist->curposition >= (plist->numofData)-1)
		return FALSE;

	(plist->curposition)++;
	*pdata = plist->arr[plist->curposition];
	return TRUE;
}

Data LRemove(List *plist)
{
	int rpos = (plist->curposition);
	Data rdata = plist->arr[plist->curposition];
	int i;
	for(i=rpos; i<(plist->numofData)-1;i++)
		plist->arr[i] = plist->arr[i+1];
	(plist->numofData)--;
	(plist->curposition)--;
	return rdata;
}

int LCount(List *plist)
{
	return (plist->numofData);
}