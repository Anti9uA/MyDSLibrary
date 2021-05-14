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
		if (symbol == '[' || symbol == '(' || symbol == '{') {	// ���� ��ȣ ����
			push(S, symbol);
			// displayStack(S);
		}
		else if (symbol == ']' || symbol == ')' || symbol == '}') {	// ������ ��ȣ ������ 
			// displayStack(S);
			if (isEmpty(S)) {	// ���� ��ȣ ����
				return FALSE;
			}
			char lparen = pop(S);	// ¦�� �´� ��ȣ ����
			if ((symbol == ']' && lparen != '[')	// ��ȣ�� �ùٸ� ������ ������ ���� ���
				|| (symbol == '}' && lparen != '{')
				|| (symbol == ')' && lparen != '(')) {
				return FALSE;
			}
		}
	}
	if (!isEmpty(S)) {	// ���� ��ȣ�� �����ִ� ���
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
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}
	
	return 0;
}
