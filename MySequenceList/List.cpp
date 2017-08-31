/*
 * List.cpp
 *
 *  Created on: 2017年8月29日
 *      Author: libo
 */

#include "List.h"
// 初始化内存
List::List(int size) {
	m_iSize = size;
	m_pList = new int[size];
	m_iLength = 0;
}

// 释放列表
List::~List() {
	delete []m_pList;
	m_pList = NULL;
}

// 清空列表
void List::ClearList()
{
	m_iLength = 0;
}

// 判断列表是否为空
bool List::ListEmpty()
{
	if (0 == m_iLength) {
		return true;
	}
	return false;
}

// 列表长度
int List::ListLength()
{
	return m_iLength;
}

// 获取指定参数
bool List::GetElem(int i, int *e)
{
	if (i < 0 || i >= m_iSize) {
		return false;
	}
	*e = m_pList[i];
	return true;
}

// 获取指定元素坐标
int List::LocateElem(int *e)
{
	for (int i = 0; i < m_iLength; i++) {
		if (m_pList[i] == *e) {
			return i;
		}
	}
	return -1;
}

// 获取指定元素前驱
bool List::PriorElem(int *currentElem, int *preElem)
{
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}else if (temp == 0) {
		return false;
	} else {
		*preElem = m_pList[temp-1];
	}
	return true;
}

// 获取指定元素后驱
bool List::NextElem(int *currentElem, int *nextElem)
{
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}else if (temp == m_iLength - 1) {
		return false;
	} else {
		*nextElem = m_pList[temp+1];
	}
	return true;
}

// 遍历列表
void List::ListTraverse()
{
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pList[i] << " ";
	}
	cout << endl;
}

// 插入元素
bool List::ListInsert(int i, int *e)
{
	if (i < 0 || i > m_iLength) {
		return false;
	}

	for (int k = m_iLength; k >= i; k--) {
		m_pList[k+1] = m_pList[k];
	}

	m_pList[i] = *e;
	m_iLength++;

	return true;
}

// 删除指定元素
bool List::ListDelete(int i, int *e)
{
	if (i < 0 || i >= m_iLength) {
		return false;
	}

	*e = m_pList[i];
	for (int k = i+1; k < m_iLength; k++) {
		m_pList[k-1] = m_pList[k];
	}
	m_iLength--;
	return true;
}

