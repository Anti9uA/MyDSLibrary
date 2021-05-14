#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack의 노드 구조를 구조체로 정의, define the structure of a node in a stack as a strucutre
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack의 마지막 요소(가장 최근에 삽입된 노드)를 나타내는 top을 구조체로 정의, define top as a structure representing the last element of stack ( most recently inserted node )
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create();					// 공백스택 생성, create a empty stack
int isFull(Stack* S);				// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isEmpty(Stack* S);				// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty
void push(Stack* S, element x);		// 스택의 top에 요소를 추가하는 연산, operation to add elements to the top of a stack
element pop(Stack* S);				// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack
element peek(Stack* S);				// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
void displayStack(Stack* S);		// 스택의 모든 요소 출력, display all elements in the stack
void clear(Stack* S);				// 스택 비우기, empty stack

#endif


