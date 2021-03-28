#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int element;

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct Node {
	element data;
	struct Node* link;
}Node;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct List {
	Node* head;
	int length;
	int (*comp)(element d1, element d2);				// 정렬 기준을 등록하기 위한 멤버
}List;

void initList(List* L);		// 공백리스트 생성 
int getLength(List* L);							// 리스트에 저장되어 있는 데이터의 수 반환 
void displayList(List* L);						// 리스트의 모든 요소 출력
void clear(List* L);								// 리스트의 전체 메모리 해제 
void setSortRule(List* L, int (*comp)(element d1, element d2));	// 정렬 기준 함수 등록 
void sortInsert(List* L, element x);				// 노드 삽입시 정렬 기준에 따라 삽입
int delete(List* L, Node* p);					// 노드 삭제 
Node* search(List* L, element x);				// 검색
void FInsert(List* L, element x);
void SInsert(List* L, element x);

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main() {

	printf("(1)공백리스트 생성하기\n");
	List list;
	initList(&list);
	displayList(&list);
	printf("리스트에 저장된 데이터 개수: %d\n\n", getLength(&list));

	setSortRule(&list, whoIsPrecede);	// 리스트의 정렬 기준이 되는 함수 등록

	printf("\n(2)리스트에 10, 80, 50 노드를 삽입하되 내림차순으로 들어가도록 하기\n");

	sortInsert(&list, 60);
	displayList(&list);
	sortInsert(&list, 80);
	displayList(&list);
	sortInsert(&list, 50);
	displayList(&list);


	printf("\n(3)리스트에서 50 노드 탐색하기\n");

	// Fill your code (SListMain.c 와 동일)


	printf("\n(4)40 노드 삽입하기(내림차순)\n");

	// Fill your code (sortInsert() 연산 이용)


	printf("\n(5)리스트에서 50 노드 삭제하기\n");

	// Fill your code (SListMain.c 와 동일)


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

int getLength(List* L) {		// SList.c와 동일
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
	L->comp = comp;		// 리스트의 멤버 comp를 초기화
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

int delete(List* L, Node* p) {		// SList.c와 동일
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

Node* search(List* L, element x) {	// SList.c와 동일
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
