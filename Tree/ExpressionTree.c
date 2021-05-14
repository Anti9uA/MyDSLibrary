#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "LinkedStack.h"

BinTree* createExpTree(char exp[]) {
	Stack* S = createStack();
	BinTree* bNode;
	int expLen = strlen(exp);
	int i;

	for (i = 0; i < expLen; i++) {
		bNode = createBT();
		if (isdigit(exp[i])) {		// ���
			setData(bNode, exp[i] - '0');
		}
		else {	// ��ȣ
			makeRSubtree(bNode, pop(S));
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		push(S, bNode);
	}
	return pop(S);
}

int evalExpTree(BinTree* bt) {
	int op1, op2;
	
	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL) {	// ���� �ڽ� ��� ��� ���� ���
		return getData(bt);
	}

	op1 = evalExpTree(getLSubtree(bt));
	op2 = evalExpTree(getRSubtree(bt));

	switch (getData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void showNodeData(int x) {
	if(0<=x && x<=9)			// �ǿ����� ���, operand output
		printf("%d ", x);
	else						// ������ ���, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	showNodeData(bt->data);		// ������ ���, operator output
	showPrefixExp(bt->left);	// ù ��° �ǿ����� ���, first operand output
	showPrefixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output

}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showNodeData(bt->data);		// ������ ���, operator output
	showInfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	showPostfixExp(bt->left);	// ù ��° �ǿ����� ���, first operand output
	showPostfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	showNodeData(bt->data);		// ������ ���, operator output

}
