/*
 * Node.h
 *
 *  Created on: 2017年8月31日
 *      Author: libo
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *nextHead;
	void printNode();

};

#endif /* NODE_H_ */
