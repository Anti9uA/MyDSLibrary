#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// 이중연결리스트의 노드 구조를 구조체로 정의, define the node structure of a doubly linked list as a structure
typedef struct ListNode {
	element data;
	struct ListNode *llink, *rlink;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의. define the head node as a structure indicating the beginning of the list
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();									// 공백리스트 생성, generate a blank list 
void insert(linkedList* L, listNode* pre, element x);	// 중간 노드로 삽입, insert as middle node 
void insertFirst(linkedList* L, element x);				// 첫 번째 노드로 삽입, insert as first node 
void insertLast(linkedList* L, element x);				// 마지막 노드로 삽입, insert as last node
int deleteNode(linkedList* L, listNode* p);				// 노드 삭제, delete node
listNode* search(linkedList* L, element x);				// 검색, search
int getLength(linkedList* L);							// 리스트에 저장되어 있는 데이터의 수 반환, return the number of data stored in the list 
void displayList(linkedList* L);						// 리스트의 모든 요소 출력, display all elements in the list
void clear(linkedList* L);								// 리스트의 전체 메모리 해제, release full memory of the list

#endif

