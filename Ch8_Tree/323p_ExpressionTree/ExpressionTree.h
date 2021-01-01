#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]); // make expression tree
int EvaluateExpTree(BTreeNode* bt); // cal expression tree

void ShowPrefixTypeExp(BTreeNode* bt); // prefix based print
void ShowInfixTypeExp(BTreeNode* bt); // Infix based print
void ShowPostfixTypeExp(BTreeNode* bt); // postfix based print

#endif