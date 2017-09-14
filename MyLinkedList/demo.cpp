#include <iostream>
#include <stdlib.h>
#include "List.h"
using namespace std;

int main(void)
{
	List *pList = new List();

	Node n1;
	n1.data = 1;
	Node n2;
	n2.data = 2;
	Node n3;
	n3.data = 3;
	Node n4;
	n4.data = 4;
	Node n5;
	n5.data = 5;

	// 插入到前面
	pList->ListInsertHead(&n1);
	pList->ListInsertHead(&n2);
	pList->ListInsertHead(&n3);
	pList->ListInsertHead(&n4);
	pList->ListInsertHead(&n5);

	// 插入到后面
	pList->ListDeleteTail(&n1);
	pList->ListDeleteTail(&n2);
	pList->ListDeleteTail(&n3);
	pList->ListDeleteTail(&n4);
	pList->ListDeleteTail(&n5);

	// 指定位置插入
	Node n6;
	n6.data = 6;
	pList->ListInsert(5, &n6);

	// 遍历
	pList->ListTraverse();

	// 删除指定位置
	Node temp;
	pList->ListDelete(5, &temp);
	cout << "temp : " << temp.data << endl;

	// 遍历
	pList->ListTraverse();

	// 前驱
	pList->PriorElem(&n5, &temp);
	cout << "temp : " << temp.data << endl;


	delete pList;
	pList = NULL;
	return 0;
}
