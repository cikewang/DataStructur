/*
 * Node.cpp
 *
 *  Created on: 2017年9月1日
 *      Author: libo
 */

#include "Node.h"

Node::Node() {
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex) {
	// 当前节点
	if(this->index == nodeIndex) {
		return this;
	}

	Node *temp = NULL;
	// 左节点
	if (this->pLChild != NULL) {
		if (this->pLChild->index == nodeIndex) {
			return this->pLChild;
		} else {
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != NULL) {
				return temp;
			}
		}
	}
	// 右节点
	if (this->pRChild != NULL) {
		if (this->pRChild->index == nodeIndex) {
			return this->pRChild;
		} else {
			temp = this->pRChild->SearchNode(nodeIndex);
			if (temp != NULL) {
				return temp;
			}
		}
	}
	return NULL;
}

// 删除节点
void Node::DeleteNode() {
	if (this->pLChild != NULL) {
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL) {
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL) {
		if (this->pParent->pLChild == this) {
			this->pParent->pLChild = NULL;
		}
		if (this->pParent->pRChild == this) {
			this->pParent->pRChild = NULL;
		}

	}

	delete this;
}

// 前序遍历
void Node::PreorderTraversal() {

	cout << this->index << " : " << this->data << endl;

	if (this->pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}
	if (this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
}

// 中序遍历
void Node::LorderTraversal() {

	if (this->pLChild != NULL) {
		this->pLChild->LorderTraversal();
	}
	cout << this->index << " : " << this->data << endl;
	if (this->pRChild != NULL) {
		this->pRChild->LorderTraversal();
	}
}

// 后序遍历
void Node::RorderTraversal() {

	if (this->pLChild != NULL) {
		this->pLChild->RorderTraversal();
	}
	if (this->pRChild != NULL) {
		this->pRChild->RorderTraversal();
	}

	cout << this->index << " : " << this->data << endl;
}

