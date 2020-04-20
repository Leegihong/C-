#include <stdio.h>
#include <stdlib.h>
#include "CLInkedlist.h"

void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->prev = NULL;
	
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->tail->next = NULL;

	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;

	plist->numofdata = 0;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next->prev = newNode;
	newNode->prev = plist->head;
	plist->head->next = newNode;

	(plist->numofdata)++;
}

int LFirst(List *plist, Data *pdata)
{
	if(plist->head->next == NULL)
		return FALSE;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}


int LNext(List *plist, Data *pdata)
{
	if(plist->cur->next->next == NULL)
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}
Data LRemove(List *plist)
{
	Node *pNode = (Node*)malloc(sizeof(Node));
	Data pdata;
	pNode = plist->cur;
	pdata = plist->cur->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;
	free(pNode);
	(plist->numofdata)--;
	return pdata;
}

int LCount(List *plist)
{
	return plist->numofdata;
}
