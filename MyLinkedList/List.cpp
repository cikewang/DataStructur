/*
 * List.cpp
 *
 *  Created on: 2017年8月29日
 *      Author: libo
 */

#include "List.h"
// 初始化内存
List::List() {
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->nextHead = NULL;
	m_iLength = 0;
}

// 释放列表
List::~List() {
	ClearList();
	delete []m_pList;
	m_pList = NULL;
}

// 清空列表
void List::ClearList()
{
	Node *currentNode = m_pList->nextHead;
	while (currentNode != NULL) {
		Node *temp = currentNode->nextHead;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->nextHead = NULL;
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

// 头部插入
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->nextHead;	// 获取头节点
	Node *newNode = new Node; 		// 从堆中申请内存，如果从栈中申请内存，函数执行完后内存就会被回收
	if (newNode == NULL) {
		return false;
	}

	m_pList->nextHead = newNode;
	newNode->data = pNode->data;
	newNode->nextHead = temp;
	m_iLength++;
	return true;
}

// 尾部插入
bool List::ListDeleteTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->nextHead != NULL) {
		currentNode = currentNode->nextHead;
	}
	Node *newNode = new Node; // 从堆中申请内存，如果从栈中申请内存，函数执行完后内存就会被回收
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->nextHead = NULL;
	currentNode->nextHead = newNode;
	m_iLength++;
	return true;
}

// 插入节点
bool List::ListInsert(int i, Node *pNode)
{
	if (i < 0 || i > m_iLength) {
		return false;
	}

	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->nextHead;
	}

	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->nextHead = currentNode->nextHead;
	currentNode->nextHead = newNode;
	m_iLength++;

	return true;
}

// 删除节点
bool List::ListDelete(int i, Node *pNode)
{
	if (i <0 || i >= m_iLength) {
		return false;
	}

	Node *currentNode = m_pList;		// 头节点
	Node *currentNodeBefore = m_pList;	// 定义当前节点的前一个节点

	// 获取第 i 个节点，所以 k <= i
	for (int k = 0; k <= i; k++) {
		currentNodeBefore = currentNode;	// 当前节点赋值给之前节点变量
		currentNode = currentNode->nextHead;// 当前节点的下一个节点赋值给当前节点变量
	}
	currentNodeBefore->nextHead = currentNode->nextHead;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;

	return true;
}

// 获取节点元素
bool List::GetElem(int i, Node *pNode)
{
	if (i <0 || i >= m_iLength) {
		return false;
	}

	Node *currentNode = m_pList;		// 头节点
	Node *currentNodeBefore = m_pList;	// 定义当前节点的前一个节点

	// 获取第 i 个节点，所以 k <= i
	for (int k = 0; k <= i; k++) {
		currentNodeBefore = currentNode;	// 当前节点赋值给之前节点变量
		currentNode = currentNode->nextHead;// 当前节点的下一个节点赋值给当前节点变量
	}
	pNode->data = currentNode->data;

	return true;
}

// 返回元素位置
int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	int i = 0;
	while(currentNode->nextHead != NULL) {
		currentNode = currentNode->nextHead;
		if (currentNode->data == pNode->data) {
			return i;
		}
		i++;
	}

	return -1;
}

// 找到节点前驱
bool List::PriorElem(Node *pCurrentElem, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while(currentNode->nextHead != NULL) {
		tempNode = currentNode;
		currentNode = currentNode->nextHead;
		if (currentNode->data == pCurrentElem->data) {
			if (tempNode == m_pList) {
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}

	return false;
}

// 找后驱
bool List::NextElem(Node *pCurrentElem, Node *pNextNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while(currentNode->nextHead != NULL) {
		currentNode = currentNode->nextHead;
		if (currentNode->data == pCurrentElem->data) {
			// 判断当前节点是否为最后一个节点
			if (currentNode->nextHead == NULL) {
				return false;
			}

			pNextNode->data = currentNode->data;
			return true;
		}
	}

	return false;
}

// 遍历
void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->nextHead != NULL) {
		currentNode = currentNode->nextHead;
		currentNode->printNode();
	}
}
