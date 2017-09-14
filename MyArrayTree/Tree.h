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
using namespace std;

class Tree {
public:
	Tree(int size, int *pRoot);
	~Tree();
	int *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, int *pNode);
	bool DeleteNode(int nodeIndex, int *pNode);
	void TreeTraverse();
private:
	int *m_pTree;
	int m_iSize;
};

#endif /* TREE_H_ */
