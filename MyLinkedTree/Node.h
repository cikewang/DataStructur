/*
 * Node.h
 *
 *  Created on: 2017年9月1日
 *      Author: libo
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <stdlib.h>

using namespace std;
class Node {
public:
	Node();
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};

#endif /* NODE_H_ */
