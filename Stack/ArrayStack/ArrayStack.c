#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// 공백스택 생성, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isFull(Stack* S) {
	return S->top == BUFSIZ - 1;
}


// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == -1;
}

// 스택의 top에 요소를 추가하는 연산, operations to add elements to the top of a stack
void push(Stack* S, element x) {
	if (isFull(S)) {
		printf("[ERROR] Stack is FULL!!\n");
		return;
	}
	else {
		S->top += 1;
		S->stack[S->top] = x;
	}
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		element e = S->stack[S->top];
		S->top -= 1;
		return e;
	}
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
element peek(Stack* S) {
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->stack[S->top];
	}
}

// 스택의 모든 요소 출력, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// 스택 비우기, empty stack
void clear(Stack* S) {
	S->top = -1;
}				

