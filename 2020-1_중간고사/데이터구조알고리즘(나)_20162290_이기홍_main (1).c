#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;


typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)  // sorted insert, nondecreasing order
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;

	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;  
	pred->next = newNode;

	(plist->numOfData)++;
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

double compAvg(List *plist, int *numNode)
{
	double meandata = 0; 
	int data;
	if(LFirst(plist, &data)){
		meandata += data;
		while(LNext(plist, &data))
			meandata += data;
	}
	meandata = meandata / (double) *numNode;
	return meandata;
}

/////4번
int recurCount(List *plist, int i)
{
	if(plist->cur == NULL)
		return i;
	plist->cur = plist->cur->next;
	i++;
	recurCount(plist, i);
}

/////5번
void recurPrint(List *plist)
{	
	if(plist->cur == NULL)
		return;
	printf("%d ->", plist->cur->data);
	plist->cur = plist->cur->next;	
	recurPrint(plist);
}

/////6번
void tailInsert(List *plist, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *pred = plist->head;
	newNode ->data = data;

	newNode->next = pred->next;
	pred->next = newNode;

	pred = pred->next;
	(plist->numOfData)++;
}

int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;    // d1이 정렬 순서상 앞선다.
	else
		return 1;    // d2가 정렬 순서상 앞서거나 같다.
}

////3번
int WhoIsPrecedeAbs(int d1, int d2)
{
	if(abs(d1) < abs(d2))
		return 0;    // d1이 정렬 순서상 앞선다.
	else
		return 1;    // d2가 정렬 순서상 앞서거나 같다.
}

int main(void)
{
	// List의 생성 및 초기화  ////////////
	List listPos, listNeg, listAbs, list;
	int data, count;
	int i=0, sum1, sum2, avg1, avg2;

	ListInit(&list);
	

	SetSortRule(&list, WhoIsPrecede);

	for(i=0;i<20;i++) {
		data = (int) (100*( rand()/(double) RAND_MAX ) - 50);
		LInsert(&list, data);
	}

	// 저장된 데이터의 전체 출력 ////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

// 문제 1, 2, 3, 4, 5, 6 에 대한 답을 여기부터 작성하시오.
//1번
	ListInit(&listPos);
	ListInit(&listNeg);

	
	if(LFirst(&list,&data)){
		if(data > 0)
			LInsert(&listPos, data);
		else
			LInsert(&listNeg, data);
		while(LNext(&list, &data)){
			if(data > 0)
			LInsert(&listPos, data);
		else
			LInsert(&listNeg, data);
		}
	}
	printf("listPos의 값:");
	if(LFirst(&listPos, &data)){
		printf("%d ", data);
		while(LNext(&listPos, &data))
			printf("%d ", data);
	}
	printf("\n");

	printf("listNeg의 값: ");
	if(LFirst(&listNeg, &data)){
		printf("%d ", data);
		while(LNext(&listNeg, &data))
			printf("%d ", data);
	}
	printf("\n");

	//2번
	data = LCount(&listPos);
	avg1 =(int)compAvg(&listPos, &data);
	data = LCount(&listNeg);
	avg2 = (int)compAvg(&listNeg, &data);
	printf("listPos의 평균값 : %d\n", avg1);
	printf("listNeg의 평균값 : %d\n", avg2);

	//3번
	ListInit(&listAbs);
	SetSortRule(&listAbs, WhoIsPrecedeAbs);

		if(LFirst(&list,&data)){
			LInsert(&listAbs, data);
		while(LNext(&list, &data)){
			LInsert(&listAbs, data);
		
		}
	}

	printf("listAbs 절대값의 순서: ");
	if(LFirst(&listAbs, &data)){
		printf("%d ", data);
		while(LNext(&listAbs, &data))
			printf("%d ", data);
	}
	printf("\n");

		
	//4번
	LFirst(&list, &data); //조회에 대한 초기화가 필요하여 LFirst함수 사용
	count = recurCount(&list, 0);
	printf("데이터 수: %d\n", count);

	//5번
	LFirst(&list, &data); //조회에 대한 초기화가 필요하여 LFirst함수 사용
	recurPrint(&list);
	printf("\n");

	//6번
	ListInit(&list);
	tailInsert(&list, 8);
	tailInsert(&list, 6);
	tailInsert(&list, 4);
	tailInsert(&list, 2);

	printf("tail_list의 값:");
	if(LFirst(&list, &data)){
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n");

	return 0;
}
