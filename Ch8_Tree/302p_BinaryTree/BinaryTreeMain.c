#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	// make 4 nodes
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	// set datas
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2); // bt2 be bt1's left child node
	MakeRightSubTree(bt1, bt3); // bt3 be bt1's right child node
	MakeLeftSubTree(bt2, bt4); // bt4 be bt2's left child node

	// print bt1's left child node's data
	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	// print bt1's left child's left child's data
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}