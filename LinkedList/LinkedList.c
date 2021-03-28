// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node* link;
} Node;
typedef struct List {
    Node* head;
    int length;
} List;

List* initList();
int getLength(List* L);
void insert(List* L, Node* pre, element x);
void insertFirst(List* L, element x);
void insertLast(List* L, element x);
int deleteNode(List* L, Node* p);
int deleteData(List* L, element x);
Node* search(List* L, element x);
void displayList(List* L);
void clear(List* L);

int main()
{
	printf("(1) 공백리스트 생성하기\n");
	List* list = initList();
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));

	printf("(2) 리스트에 10, 50 노드를 순서대로 삽입하기\n");
	insertFirst(list, 10);
	insert(list, list->head, 50);
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));

	printf("(3) 리스트에 마지막에 80 노드 추가하기\n");
	insertLast(list, 80);
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));

	printf("(4) 리스트에서 50 노드 탐색하기\n");
	if (search(list, 50)->data != NULL) {
		printf("%d 노드를 찾았습니다.\n\n", search(list, 50)->data);
	}

	printf("(5) 50 노드 뒤에 60 노드 삽입하기\n");
	insert(list, search(list, 50), 60);
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));

	printf("(6) 리스트에서 80 노드 삭제하기 (node 사용)\n");
	if (deleteNode(list, search(list, 80)) == 1) {
		printf("노드 삭제 성공!\n");
	}
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));

	printf("(6) 리스트에서 50 노드 삭제하기 (element 사용)\n");
	if (deleteData(list, 50) == 1) {
		printf("노드 삭제 성공!\n");
	}
	displayList(list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(list));
	
	clear(list);
}

List* initList() {
	List* L;
	L = (List*)malloc(sizeof(List));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(List* L) {
    return L->length;
}

void insert(List* L, Node* pre, element x) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));	// init new node
	newNode->data = x;

	if (L->head == NULL) {	// if empty list
		newNode->link == NULL;
		L->head = newNode;
	}

	else if (pre == NULL) {	// insert first node
		newNode->link = L->head;
		L->head = newNode;
	}
	
	else {	// insert normal
		newNode->link = pre->link;
		pre->link = newNode;
	}

	L->length++;	// length+1
}

void insertFirst(List* L, element x) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));	// init node
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;	// head points new node
	L->length++;	// length++
}

void insertLast(List* L, element x) {
	Node *newNode, *temp;
	newNode = (Node*)malloc(sizeof(Node));	// init node
	newNode->data = x;
	newNode->link = NULL;

	if (L->head == NULL) {	// if empty list
		L->head = newNode;
	}

	else {
		temp = L->head;
		while (temp->link != NULL) {	// find end node
			temp = temp->link;
		}
		temp->link = newNode;	// link last node
	}
	L->length++;	// length++
}

int deleteNode(List* L, Node* p) {	// 1: deletion complete, 0: deletion failed
	Node* pre;
	if (L->head == NULL) return 0;	// empty node
	if (p == NULL) return 0;	
	pre = L->head;
	while (pre->link != p) {	// find node to delete
		pre = pre->link;
		if (pre == NULL) return 0;	// search failed
	}
	pre->link = p->link;	// disconnect node
	free(p);	// free node
	L->length--;	// length --
	return 1;	// deletion completed
}

int deleteData(List* L, element x) {
	Node* pre;
	if (L->head == NULL) return 0;	// empty node
	if (x == NULL) return 0;
	pre = L->head;
	if (pre->data == x) {
		L->head = pre->link;
		free(pre);
		return 1;
	}
	while (pre->link != NULL) {
		if (pre->link->data == x) {
			Node* temp = pre->link;

			if (temp->link != NULL) {
				pre->link = temp->link;
			}
			else {
				pre->link = NULL;
			}
			free(temp);
		}
		pre = pre->link;
	}
	L->length--;
	return 1;
}

Node* search(List* L, element x) {
	Node* temp = L->head;
	while (temp->data != x) {
		temp = temp->link;
		if (temp == NULL) return 0;
	}
	return temp;
}

void displayList(List* L) {
	Node* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(List* L) {
	Node* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}