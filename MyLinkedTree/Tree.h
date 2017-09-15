/*
 * Tree.h
 *
 *  Created on: 2017年9月1日
 *      Author: libo
 */

#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <stdlib.h>
#include "Node.h"

using namespace std;

class Tree {
public:
	Tree();						// 创建树
	~Tree();					// 销毁树
	Node *SearchNode(int nodeIndex);	// 搜索节点
	bool AddNode(int nodeIndex, int dirction, Node *pNode);	// 添加节点
	bool DeleteNode(int nodeIndex, Node *pNode);		// 删除节点
	void PreorderTraversal();
	void LorderTraversal();
	void RorderTraversal();
private:
	Node *m_pRoot;
};

#endif /* TREE_H_ */
