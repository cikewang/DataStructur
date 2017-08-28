#include <iostream>
#include <stdlib.h>
using namespace std;
#include "MyStack.h"

int main(void) {

	MyStack *pStack = new MyStack(5);

	pStack->push('a');
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e');

	char elem;
	pStack->pop(elem);
	cout << "elem : " << elem << endl;

	pStack->push('f');
	pStack->stackTraverse();


	delete pStack;
	pStack = NULL;

	return 0;
}
