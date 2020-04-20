#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "emp.h"

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	emp *Emp;
	int i;
	ListInit(&list);
	

	Emp = setEmp(1234, "daniel");
	LInsert(&list, Emp);
	
	Emp = setEmp(5678, "seoul");
	LInsert(&list, Emp);

	Emp = setEmp(9012, "korea");
	LInsert(&list, Emp);

	Emp = setEmp(8628, "yonsei");
	LInsert(&list, Emp);
	
	i = 0;
	// 리스트에 저장된 데이터를 연속 3회 출력 ///////
	if(LFirst(&list, &Emp))
	{
		showEmp(Emp);
		
		while(LNext(&list, &Emp)&&(i!=4))
		{
			showEmp(Emp);
			i++;
		}
	}
	printf("\n");

	

	// 다음 당직 ///////
	if(LFirst(&list, &Emp))
	{
		printf("오늘의 당직");
		showEmp(Emp);
		
		for(i=0; i<7; i++)
		{
			if(LNext(&list, &Emp))
				printf("\n");
		}
		
		
	}
	printf("7일뒤 당직은 :");
	showEmp(Emp);
	return 0;
}