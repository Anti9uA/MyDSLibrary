#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

// 연산자, 피연산자, 괄호를 처리하기 위한 enumeration type 선언, define of the enumeration type to handle operators, operands, and parentheses
typedef enum { 
	lparen, rparen, plus, minus, multiply, divide, mod, eos, operand
}precedence;

precedence getToken(char ch);			// 연산자, 피연산자, 괄호 -> enueration type 변환, operator, operand, parenthesis -> enueration type transform
char printToken(precedence token);		// enumeration type에 따라 연산자, 괄호 출력, operator, parenthesis display according to enumeration type
int prec(precedence symbol);			// 연산자 우선순위 계산: 괄호 < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
char* toPostfix(Stack* S, char* exp);	// 중위표기식 -> 후위표기식 변환 연산, inflix notation -> postfix notation transform operation
float evalPostfix(Stack* S, char* exp);	// 후위표기식의 계산 연산, computation of postfix notaion
int WhoPrecOp(char op1, char op2);

#endif
