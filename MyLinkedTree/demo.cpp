#include <iostream>
#include <stdlib.h>
#include "Tree.h"

using namespace std;

int main(void)
{
//	前序遍历：（根左右） 0134256
//	中序遍历：（左根右） 3140526
//	后序遍历：（左右根） 3415620


	Tree *tree = new Tree();

	Node *n1 = new Node();
	n1->index = 1;
	n1->data = 1;

	Node *n2 = new Node();
	n2->index = 2;
	n2->data = 2;

	Node *n3 = new Node();
	n3->index = 3;
	n3->data = 3;

	Node *n4 = new Node();
	n4->index = 4;
	n4->data = 4;

	Node *n5 = new Node();
	n5->index = 5;
	n5->data = 5;

	Node *n6 = new Node();
	n6->index = 6;
	n6->data = 6;

	tree->AddNode(0, 0, n1);
	tree->AddNode(0, 1, n2);

	tree->AddNode(1, 0, n3);
	tree->AddNode(1, 1, n4);

	tree->AddNode(2, 0, n5);
	tree->AddNode(2, 1, n6);

	cout << "前序遍历"<< endl;
	tree->PreorderTraversal();

//	cout << "中序遍历" << endl;
//	tree->LorderTraversal();
//
//	cout << "后序遍历" <<endl;
//	tree->RorderTraversal();


	tree->DeleteNode(2, NULL);
	cout << "前序遍历"<< endl;
	tree->PreorderTraversal();

	delete tree;
	tree = NULL;

	return 0;
}
