/*
 * List.h
 *
 *  Created on: 2017年8月29日
 *      Author: libo
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

class List {
public:
	List(int size);
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, int *e);
	int LocateElem(int *e);
	bool PriorElem(int *currentElem, int *preElem);
	bool NextElem(int *currentElem, int *nextElem);
	void ListTraverse();
	bool ListInsert(int i, int *e);
	bool ListDelete(int i, int *e);

private:
	int *m_pList;	// 内存指针
	int m_iSize;	// 列表大小
	int m_iLength;	// 列表长度
};

#endif /* LIST_H_ */
