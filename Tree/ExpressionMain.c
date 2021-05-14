#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BinTree* bt = createExpTree(exp);	
	
	printf("\n전위 표기법의 수식: ");	// Formula for prefix notation:
	showPrefixExp(bt);
	printf("\n\n");
	
	printf("중위 표기법의 수식: ");	// Formula for infix notation:
	showInfixExp(bt);
	printf("\n\n");
	
	printf("후위 표기법의 수식: ");	// Formula for postfix notation
	showPostfixExp(bt);
	printf("\n\n");
	
	printf("연산 결과: %d \n", evalExpTree(bt));	// Computational Results:
	
	return 0;
}
