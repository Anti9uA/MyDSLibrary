#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ, operator, operand, parenthesis -> enueration type transform
precedence getToken(char ch) {
	precedence token;
	switch(ch) {
		case '(':	token = lparen;		break;
		case ')': 	token = rparen;		break;
		case '+':	token = plus;		break;
		case '-':	token = minus;		break;
		case '*':	token = multiply;	break;
		case '/':	token = divide;		break;
		case '%':	token = mod;		break;
		case '\0':	token = eos;		break;
		default:	token = operand;
	}
	
	return token;
}

// enumeration type�� ���� ������, ��ȣ ���, operator, parenthesis display according to enumeration type
char printToken(precedence token) {
	char ch;
	switch(token) {
		case lparen:	ch = '(';	break;
		case rparen:	ch = ')';	break;
		case plus:		ch = '+';	break;
		case minus:		ch = '-';	break;
		case multiply:	ch = '*';	break;
		case divide:	ch = '/';	break;
		case mod:		ch = '%';	break; 
	}
	
	return ch;
}

// ������ �켱���� ���: ��ȣ < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
int prec(precedence symbol) {
	switch(symbol) {
		case ')':
		case '(':		return 0;
		case '+':
		case '-':		return 1;
		case '*':
		case '/':
		case '%':		return 2;
	}
}

int WhoPrecOp(char op1, char op2) {	// �켱���� �� �Լ�
	int op1Prec = prec(op1);
	int op2Prec = prec(op2);

	if (op1Prec > op2Prec) {	// �켱���� ����
		return 1;
	}

	else if (op1Prec < op2Prec) {	// �켱���� ��߳�
		return -1;
	}

	else {	
		return 0;
	}
}

// ����ǥ��� -> ����ǥ��� ��ȯ ����, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// �������� ���� ���, recording the type of operator
	S = create();
	len = strlen(exp);
	char tok, popOp;

	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) {	// ���ڸ� ��� ���ۿ� ����
			result[n++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				push(S, tok);
				break;

			case ')':
				while (1) {
					popOp = pop(S);		// �����ȣ ����
					if (popOp == '(') { break; }	// ������ ��ȣ
					result[n++] = popOp;
				}	// end while
				break;

			case '+': case '-': case '*': case '/':
				while(!isEmpty(S) && WhoPrecOp(peek(S), tok) >= 0){	// ������ �켱���� ��
					result[n++] = pop(S);
				}
				push(S, tok);
				break;
			}	// end switch
		} // end else
	} // end for

	while (!isEmpty(S)) {
		result[n++] = pop(S);
	}

	return result;
}

// ����ǥ����� ��� ����, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	int n = 0;
	char tok, op1, op2;
	S = create();
	int len = strlen(exp);
	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			push(S, tok - '0');
		}

		else {
			op2 = pop(S);	// 2��° ������ ��
			op1 = pop(S);	// 1��° ������ ��

			switch (tok) {
			case '+':
				push(S, op1 + op2);
				break;

			case '-':
				push(S, op1 - op2);
				break;

			case '*':
				push(S, op1 * op2);
				break;

			case '/':
				push(S, op1 / op2);
				break;

			case '%':
				push(S, op1 % op2);
				break;
			}	// end switch
		}
	}	// end for
	return pop(S);
}
