/*
 * MyStack.h
 *
 *  Created on: 2017年8月28日
 *      Author: libo
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <iostream>
using namespace std;

class MyStack {
public:
	MyStack(int size);	// 分配内存初始化栈空间，设定栈容量
	virtual ~MyStack(); // 回收栈空间内存
	bool stackEmpty();	// 判断栈是否为空，为空返回 true，非空返回 false
	bool stackFull();	// 判断栈是否已满，已满返回 true，否则返回 false
	void clearFull();	// 清空栈
	int stackLength();	// 已有元素的个数
	bool push(char elem); // 元素入栈，栈顶上升
	bool pop(char &elem); // 元素出站，栈顶下降
	void stackTraverse(); // 遍历栈中的元素
private:
	char *m_pBuffer;	// 栈空间指针
	int m_iSize;		// 栈容量
	int m_iTop;			// 栈顶，栈中元素的个数
};

#endif /* MYSTACK_H_ */
