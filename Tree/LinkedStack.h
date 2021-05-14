#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include "BinaryTree.h"

#define ERROR NULL
#define TRUE 1
#define FALSE 0

typedef BinTree* element;

// Stack의 노드 구조를 구조체로 정의, define stack's node structure as a structure
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack의 마지막 요소(가장 최근에 삽입된 노드)를 나타내는 top을 구조체로 정의, define a top as a structure that represents the last element of stack ( most recently inserted node ) 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* createStack();				// 공백스택 생성, create a empty stack
int getLength(Stack* S);			// 스택에 저장된 요소 개수를 반환하는 연산, operations that return the number of elements stored in the stack
int isFull(Stack* S);				// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isEmpty(Stack* S);				// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty
void push(Stack* S, element x);		// 스택의 top에 요소를 추가하는 연산, operations that add elements to top of stack
element pop(Stack* S);				// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations to delete and return the last stored element on the stack
element peek(Stack* S);				// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
void displayStack(Stack* S);		// 스택의 모든 요소 출력, output all elements in the stack 
void clear(Stack* S);				// 스택 비우기, empth stack

#endif


