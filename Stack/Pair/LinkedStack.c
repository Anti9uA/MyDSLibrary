#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full					
int isFull(Stack* S) {
	return 0;
}

// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == NULL;
}

// 스택의 top에 요소를 추가하는 연산, operation to add elements to the top of a stack			
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack
element pop(Stack* S) {
	stackNode* temp;
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
		return e;
	}
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack			
element peek(Stack* S) {
	element e;
	if (isEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->top->data;
	}
}

// 스택의 모든 요소 출력, display all elements in the stack 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기, empty stack
void clear(Stack* S) {
	stackNode* p;
	while (S->top != NULL) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


