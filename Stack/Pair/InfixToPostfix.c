#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// 연산자, 피연산자, 괄호 -> enueration type 변환, operator, operand, parenthesis -> enueration type transform
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

// enumeration type에 따라 연산자, 괄호 출력, operator, parenthesis display according to enumeration type
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

// 연산자 우선순위 계산: 괄호 < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
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

int WhoPrecOp(char op1, char op2) {	// 우선순위 비교 함수
	int op1Prec = prec(op1);
	int op2Prec = prec(op2);

	if (op1Prec > op2Prec) {	// 우선순위 정상
		return 1;
	}

	else if (op1Prec < op2Prec) {	// 우선순위 어긋남
		return -1;
	}

	else {	
		return 0;
	}
}

// 중위표기식 -> 후위표기식 변환 연산, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// 연산자의 종류 기록, recording the type of operator
	S = create();
	len = strlen(exp);
	char tok, popOp;

	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) {	// 숫자면 결과 버퍼에 저장
			result[n++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				push(S, tok);
				break;

			case ')':
				while (1) {
					popOp = pop(S);		// 정상괄호 추출
					if (popOp == '(') { break; }	// 비정상 괄호
					result[n++] = popOp;
				}	// end while
				break;

			case '+': case '-': case '*': case '/':
				while(!isEmpty(S) && WhoPrecOp(peek(S), tok) >= 0){	// 연산자 우선순위 비교
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

// 후위표기식의 계산 연산, computation of postfix notaion
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
			op2 = pop(S);	// 2번째 연산자 팝
			op1 = pop(S);	// 1번째 연산자 팝

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
