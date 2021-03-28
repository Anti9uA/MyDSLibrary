#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char* element;
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
int delete(List* L, Node* p);
Node* search(List* L, element x);
void displayList(List* L);
void clear(List* L);
void reverse(List* L);


int main() {

	printf("(1) ���鸮��Ʈ �����ϱ�\n");
	List* list = initList();
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));

	printf("(2) ����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");
	insertFirst(list, "��");
	insert(list, list->head, "ȭ");
	insertLast(list, "��");
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));

	printf("(3) ����Ʈ�� ���� �������� �� ��� �����ϱ�\n");
	insertLast(list, "��");
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));

	printf("(4) ȭ ��� �ڿ� �� ��� �����ϱ�\n");
	insert(list, search(list, "ȭ"), "��");
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));

	printf("(5) ����Ʈ���� �� ��� Ž���ϱ�\n");
	if (search(list, "��") == NULL) {
		printf("ã�� �����Ͱ� �����ϴ�.\n\n");
	}
	
	printf("(6) ����Ʈ ������ �������� �ٲٱ�\n");
	reverse(list);
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));

	printf("(7) ����Ʈ���� ȭ ��� �����ϱ�\n");
	if (delete(list, search(list, "ȭ")) == 1) {
		printf("��� ���� ����!\n");
	}
	displayList(list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(list));


	clear(list);

	return 0;
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
	Node* newNode, * temp;
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

int delete(List* L, Node* p) {	// 1: deletion complete, 0: deletion failed
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

Node* search(List* L, element x) {
	Node* temp = L->head;
	while (temp->data != x) {
		temp = temp->link;
		if (temp == NULL) return temp;
	}
	return temp;
}

void displayList(List* L) {
	Node* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
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

void reverse(List* L) {
	Node* p = L->head;	// p: current node, q: pre node
	Node *r, *q;	
	q = NULL;
	while (p != NULL) {
		r = q;	// follow r => q, q => p 
		q = p;
		p = p->link;	// move p
		q->link = r;	// reverse direction of q
	}
	L->head = q;	// reversed head pointer
}