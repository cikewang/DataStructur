/*
 * List.h
 *
 *  Created on: 2017年8月29日
 *      Author: libo
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <stdlib.h>
#include "Node.h"
using namespace std;

class List {
public:
	List();
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node *pNode);
	int LocateElem(Node *pNode);
	bool PriorElem(Node *pCurrentElem, Node *pPreNode);
	bool NextElem(Node *pCurrentElem, Node *pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node *pNode);
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListDeleteTail(Node *pNode);

private:
	Node *m_pList;	// 内存指针
	int m_iLength;	// 列表长度
};

#endif /* LIST_H_ */
