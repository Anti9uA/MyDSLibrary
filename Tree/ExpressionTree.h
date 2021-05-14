#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BinTree* createExpTree(char exp[]);
int evalExpTree(BinTree* bt);

void showPrefixExp(BinTree* bt);
void showInfixExp(BinTree* bt);
void showPostfixExp(BinTree* bt);

#endif
