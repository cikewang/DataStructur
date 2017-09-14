#include <iostream>
#include <stdlib.h>
#include "Tree.h"
using namespace std;

int main(void)
{
	// 3 5 8 2 6 9 7
	int root = 3;
	Tree *t  = new Tree(10, &root);

	int node1 = 5;
	int node2 = 8;
	t->AddNode(0, 0, &node1);
	t->AddNode(0, 1, &node2);

	int node3 = 2;
	int node4 = 6;
	t->AddNode(1, 0, &node3);
	t->AddNode(1, 1, &node4);

	int node5 = 9;
	int node6 = 7;
	t->AddNode(2, 0, &node5);
	t->AddNode(2, 1, &node6);

	int *temp = t->SearchNode(2);
	cout << "temp : " << *temp << " : " << temp  << endl;

	// 遍历
	t->TreeTraverse();

	int node;
	t->DeleteNode(2, &node);
	cout << "node : " << &node << " : " << node  << endl;

	// 遍历
	t->TreeTraverse();


	return 0;
}
