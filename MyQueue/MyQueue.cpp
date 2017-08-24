/*
 * MyQueue.cpp
 *      Author: libo
 */

#include <iostream>
#include "MyQueue.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity) {

	m_iQueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	m_pQueue = new int[queueCapacity];	// 从堆中申请内存，初始化队列大小


}

MyQueue::~MyQueue() {
	delete []m_pQueue;
	m_pQueue = NULL;
}

// 清空队列
void MyQueue::ClearQueue() {
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

// 判断当前队列是否为空
bool MyQueue::QueueEmpty() const {
	if (m_iQueueLen == 0) {
		return true;
	}
	return false;
}

// 队列长度
int MyQueue::QueueLength() const {
	return m_iQueueLen;
}

// 判断队列是否满了
bool MyQueue::QueueFull() const {
	if (m_iQueueLen == m_iQueueCapacity) {
		return true;
	}
	return false;
}

// 新元素入队
bool MyQueue::EnQueue(int element) {
	// 判断队里是否满了
	if (QueueFull()) {
		return false;
	}

	// 将新元素添加到队尾
	m_pQueue[m_iTail] = element;
	m_iTail++;	// 队尾指针向后移动
	m_iTail = m_iTail % m_iQueueCapacity;


	m_iQueueLen++;
	return true;

}
// 首元素出队
bool MyQueue::DeQueue(int &element) {
	// 判断队列是否为空
	if (QueueEmpty()) {
		return false;
	}


	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead = m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

// 遍历队列
void MyQueue::QueueTraverse() {

	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++) {

		cout << m_pQueue[i%m_iQueueCapacity] << endl;
	}
}









