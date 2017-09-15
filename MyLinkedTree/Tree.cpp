/*
 * Tree.cpp
 *
 *  Created on: 2017年9月1日
 *      Author: libo
 */

#include "Tree.h"

//初始化树
Tree::Tree() {
	m_pRoot = new Node();
}

Tree::~Tree() {
	// 两种方式
	//DeleteNode(0, NULL);
	m_pRoot->DeleteNode();

}

// 搜索节点
Node *Tree::SearchNode(int nodeIndex) {

	return m_pRoot->SearchNode(nodeIndex);
}

// 添加节点
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode) {

	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}

	Node *node = new Node();
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;

	// 添加到左节点
	if (direction == 0) {
		temp->pLChild = node;
	}

	// 添加到右节点
	if (direction == 1) {
		temp->pRChild = node;
	}

	return true;
}

// 删除节点
bool Tree::DeleteNode(int nodeIndex, Node *pNode) {

	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}

	if (pNode != NULL) {
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;
}

// 前序遍历
void Tree::PreorderTraversal() {
	m_pRoot->PreorderTraversal();
}

// 中序遍历
void Tree::LorderTraversal() {
	m_pRoot->LorderTraversal();
}

// 后序遍历
void Tree::RorderTraversal() {
	m_pRoot->RorderTraversal();
}

