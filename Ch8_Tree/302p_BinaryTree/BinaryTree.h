#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void); // make new node
BTData GetData(BTreeNode* bt); // return saved data
void SetData(BTreeNode* bt, BTData data); // save data

// return address of the subtree
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // connect sub to main's left
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // connect sub to main's right

#endif