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
		if (isdigit(exp[i])) {		// 상수
			setData(bNode, exp[i] - '0');
		}
		else {	// 기호
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
	
	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL) {	// 양쪽 자식 노드 모두 없는 경우
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
	if(0<=x && x<=9)			// 피연산자 출력, operand output
		printf("%d ", x);
	else						// 연산자 출력, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	showNodeData(bt->data);		// 연산자 출력, operator output
	showPrefixExp(bt->left);	// 첫 번째 피연산자 출력, first operand output
	showPrefixExp(bt->right);	// 두 번째 피연산자 출력, second operand output

}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showNodeData(bt->data);		// 연산자 출력, operator output
	showInfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) {
	if (bt == NULL)
		return;

	showPostfixExp(bt->left);	// 첫 번째 피연산자 출력, first operand output
	showPostfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	showNodeData(bt->data);		// 연산자 출력, operator output

}
