#include <iostream>
#include <stdlib.h>
#include "List.h"
using namespace std;

int main(void)
{
	List *l = new List(10);

	// 插入
	int e0 = 4;
	int e1 = 5;
	int e2 = 7;
	int e3 = 3;
	int e4 = 1;
	int e5 = 9;
	int e6 = 2;
	l->ListInsert(0, &e0);
	l->ListInsert(1, &e1);
	l->ListInsert(2, &e2);
	l->ListInsert(3, &e3);
	l->ListInsert(4, &e4);
	l->ListInsert(5, &e5);
	l->ListInsert(6, &e6);

	// 临时插入
	l->ListInsert(3, &e6);

	// 遍历
	l->ListTraverse();

	// 删除
	int temp = 0;
	l->ListDelete(0, &temp);
	cout << "temp : " << temp << endl;

	// 遍历
	l->ListTraverse();

	// 获取前驱元素
	l->PriorElem(&e3, &temp);
	cout << temp << endl;

	// 获取后驱元素
	l->NextElem(&e3, &temp);
	cout << temp << endl;

	// 遍历
	l->ListTraverse();

//	if (!l->ListEmpty()) {
//		cout << "不为空" << endl;
//	}

	//	l->ClearList();

//	if (l->ListEmpty()) {
//		cout << "为空" << endl;
//	}

	delete l;

	return 0;
}
