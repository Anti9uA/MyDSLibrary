#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i = 0;
	int length = strlen(exp);
	while (exp[i] != NULL) {
		symbol = exp[i++];
		if (symbol == '[' || symbol == '(' || symbol == '{') {	// 왼쪽 괄호 스택
			push(S, symbol);
			// displayStack(S);
		}
		else if (symbol == ']' || symbol == ')' || symbol == '}') {	// 오른쪽 괄호 나오면 
			// displayStack(S);
			if (isEmpty(S)) {	// 뺴낼 괄호 없음
				return FALSE;
			}
			char lparen = pop(S);	// 짝에 맞는 괄호 빼냄
			if ((symbol == ']' && lparen != '[')	// 괄호가 올바른 순서로 나오지 않은 경우
				|| (symbol == '}' && lparen != '{')
				|| (symbol == ')' && lparen != '(')) {
				return FALSE;
			}
		}
	}
	if (!isEmpty(S)) {	// 뺴낼 괄호가 남아있는 경우
		return FALSE;
	}
	return TRUE;
}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};
	
	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
		else
			printf("-> 수식의 괄호가 틀렸습니다!\n");
	}
	
	return 0;
}
