#include <iostream>
#include <stdlib.h>
#include "CMap.h"
using namespace std;



/*
 *		A
 *    /	  \
 *	 B      D
 *  / \    / \
 * C   F  G   H
 *  \ /
 *   E
 */
int main(void) {

	CMap *pMap = new CMap(8);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	// 邻接矩阵设置  -- 无向图
	pMap->setValueTomatrixForUndirectedGraph(0, 1); // A - B
	pMap->setValueTomatrixForUndirectedGraph(0, 3); // A - D
	pMap->setValueTomatrixForUndirectedGraph(1, 2); // B - C
	pMap->setValueTomatrixForUndirectedGraph(1, 5); // B - F
	pMap->setValueTomatrixForUndirectedGraph(3, 6); // D - G
	pMap->setValueTomatrixForUndirectedGraph(3, 7); //
	pMap->setValueTomatrixForUndirectedGraph(6, 7); //
	pMap->setValueTomatrixForUndirectedGraph(2, 4); //
	pMap->setValueTomatrixForUndirectedGraph(4, 5); //

	// 打印
	pMap->printMatrix();
	cout << endl;

	// 深度优先遍历
	pMap->depthFirstTraverse(0);

	cout << endl;

	// 广度优先遍历
	pMap->resetNode();
	pMap->breadthFirstTraverse(0);


	return 0;
}
