#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "emp.h"

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
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
	// ����Ʈ�� ����� �����͸� ���� 3ȸ ��� ///////
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

	

	// ���� ���� ///////
	if(LFirst(&list, &Emp))
	{
		printf("������ ����");
		showEmp(Emp);
		
		for(i=0; i<7; i++)
		{
			if(LNext(&list, &Emp))
				printf("\n");
		}
		
		
	}
	printf("7�ϵ� ������ :");
	showEmp(Emp);
	return 0;
}