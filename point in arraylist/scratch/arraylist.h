#include "pont.h"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef Point * Data;

typedef struct __ArrayList
{
	Data arr[LIST_LEN];
	int numofData;
	int curposition;
}ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);

Data LRemove(List *plist);
int LCount(List *plist);
