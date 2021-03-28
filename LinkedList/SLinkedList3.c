#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int element;

// �ܼ����Ḯ��Ʈ�� ��� ������ ����ü�� ����
typedef struct Node {
	element data;
	struct Node* link;
}Node;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct List {
	Node* head;
	int length;
	int (*comp)(element d1, element d2);				// ���� ������ ����ϱ� ���� ���
}List;

void initList(List* L);		// ���鸮��Ʈ ���� 
int getLength(List* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ 
void displayList(List* L);						// ����Ʈ�� ��� ��� ���
void clear(List* L);								// ����Ʈ�� ��ü �޸� ���� 
void setSortRule(List* L, int (*comp)(element d1, element d2));	// ���� ���� �Լ� ��� 
void sortInsert(List* L, element x);				// ��� ���Խ� ���� ���ؿ� ���� ����
int delete(List* L, Node* p);					// ��� ���� 
Node* search(List* L, element x);				// �˻�
void FInsert(List* L, element x);
void SInsert(List* L, element x);

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main() {

	printf("(1)���鸮��Ʈ �����ϱ�\n");
	List list;
	initList(&list);
	displayList(&list);
	printf("����Ʈ�� ����� ������ ����: %d\n\n", getLength(&list));

	setSortRule(&list, whoIsPrecede);	// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���

	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 �����ϵ� ������������ ������ �ϱ�\n");

	sortInsert(&list, 60);
	displayList(&list);
	sortInsert(&list, 80);
	displayList(&list);
	sortInsert(&list, 50);
	displayList(&list);


	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");

	// Fill your code (SListMain.c �� ����)


	printf("\n(4)40 ��� �����ϱ�(��������)\n");

	// Fill your code (sortInsert() ���� �̿�)


	printf("\n(5)����Ʈ���� 50 ��� �����ϱ�\n");

	// Fill your code (SListMain.c �� ����)


	//clear(&list);

	return 0;
}

void initList(List* L) {
	L->head = (List*)malloc(sizeof(List));
	// L->head = NULL;
	L->head = NULL;
	L->length = 0;
	L->comp = NULL;
}

int getLength(List* L) {		// SList.c�� ����
	return L->length;
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

void setSortRule(List* L, int (*comp)(element d1, element d2)) {
	L->comp = comp;		// ����Ʈ�� ��� comp�� �ʱ�ȭ
}

void sortInsert(List* L, element x) {
	Node* newNode = (Node*)malloc(sizeof(newNode));
	newNode->data = x;

	if (L->comp == NULL || L->length == 0)
	{
		FInsert(L, x);
	}
	else
	{
		SInsert(L, x);
	}


}

int delete(List* L, Node* p) {		// SList.c�� ����
	Node* pre;
	if (L->head == NULL) return FALSE;	// empty node
	if (p == NULL) return FALSE;
	pre = L->head;
	while (pre->link != p) {	// find node to delete
		pre = pre->link;
		if (pre == NULL) return FALSE;	// search failed
	}
	pre->link = p->link;	// disconnect node
	free(p);	// free node
	L->length--;	// length --
	return TRUE;	// deletion completed
}

Node* search(List* L, element x) {	// SList.c�� ����
	Node* temp = L->head;
	while (temp->data != x) {
		temp = temp->link;
		if (temp == NULL) return 0;
	}
	return temp;
}

void FInsert(List* L, element x) {
	Node* newNode = (Node*)malloc(sizeof(newNode));
	newNode->data = x;

	newNode->link = L->head;
	L->head = newNode;

	L->length++;
}

void SInsert(List* L, element x) {
	Node* newNode = (Node*)malloc(sizeof(newNode));
	Node* pre = L->head;
	newNode->data = x;

	while (pre->link != NULL && L->comp(x, pre->link->data) != 0) {
		pre = pre->link;
	}
	newNode->link = pre->link;
	pre->link = newNode;
	L->length++;
}
