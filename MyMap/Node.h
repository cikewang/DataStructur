/*
 * Node.h
 *
 *  Created on: 2017年9月20日
 *      Author: libo
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(char data = 0);
	char m_cData;
	bool m_bIsVisited;
};

#endif /* NODE_H_ */
