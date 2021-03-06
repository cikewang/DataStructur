/*
 * Tree.cpp
 *
 *  Created on: 2017年9月1日
 *      Author: libo
 */

#include "Tree.h"

Tree::Tree(int size, int *pRoot) {

	m_iSize = size;
	m_pTree = new int[size];	// 分配树内存大小

	for (int i = 0; i < size; i++) {
		m_pTree[i] = 0;			// 初始化树的每个元素
	}
	m_pTree[0] = *pRoot;
}

Tree::~Tree() {
	delete []m_pTree;
	m_pTree = NULL;
}

// 搜索节点
int *Tree::SearchNode(int nodeIndex)
{
	if (nodeIndex < 0 || nodeIndex > m_iSize) {
		return NULL;
	}

	if (m_pTree[nodeIndex] == 0) {
		return NULL;
	}

	return &m_pTree[nodeIndex];
}

// 添加节点
bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
	if (nodeIndex < 0 || nodeIndex > m_iSize) {
		return false;
	}

	if (m_pTree[nodeIndex] == 0) {
		return false;
	}

	if (direction == 0) {
		if (nodeIndex * 2 + 1 >= m_iSize) {
			return false;
		}
		if (m_pTree[nodeIndex * 2+1] != 0) {
			return false;
		}
		m_pTree[nodeIndex * 2+1] = *pNode;
	}
	if (direction == 1) {
		if (nodeIndex * 2 + 2 >= m_iSize) {
			return false;
		}
		if (m_pTree[nodeIndex * 2+2] != 0) {
			return false;
		}
		m_pTree[nodeIndex * 2+2] = *pNode;
	}

	return true;
}


bool Tree::DeleteNode(int nodeIndex, int *pNode)
{
	if (nodeIndex < 0 || nodeIndex > m_iSize) {
		return false;
	}

	if (m_pTree[nodeIndex] == 0) {
		return false;
	}

	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}

void Tree::TreeTraverse()
{
	for (int i = 0; i < m_iSize; i++) {
		cout << m_pTree[i] << endl;
	}
}

