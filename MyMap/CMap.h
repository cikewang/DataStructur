/*
 * CMap.h
 *
 *  Created on: 2017年9月20日
 *      Author: libo
 */

#ifndef CMAP_H_
#define CMAP_H_

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#include "Node.h"

class CMap {
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);	// 向图中加入顶点
	void resetNode();			// 重置顶点
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);	// 为有向图设置邻接矩阵
	bool setValueTomatrixForUndirectedGraph(int row, int col, int val = 1);	// 为无向图设置邻接矩阵
	void printMatrix();		// 打印邻接矩阵
	void depthFirstTraverse(int nodeIndex);		// 深度优先遍历
	void breadthFirstTraverse(int nodeIndex);	// 广度优先遍历

private:
	bool getValueFromMatrix(int row, int col, int &val);	// 从矩阵中获取权值
	void breadthFirstTraverseTmpl(vector<int> preVec);		// 广度优先遍历实现函数

private:
	int m_iCapacity;	// 图中最大可以容纳的顶点数
	int m_iNodeCount;	// 已经添加的顶点个数
	Node *m_pNodeArray;	// 用于存放顶点数组
	int *m_pMatrix;		// 用于存放邻接矩阵
};

#endif /* CMAP_H_ */
