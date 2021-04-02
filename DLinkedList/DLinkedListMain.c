#include <stdio.h>
#include "DLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)이중 연결 리스트 생성하기\n");	// (1)To create a doubly linked list
	L = initList();
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(2)리스트에 10 노드를 첫 번째 노드로 삽입하기\n");	// (2)Inserting 10 node into the list as the first node
	insertFirst(L, 10);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(3)리스트의 50 노드를 마지막 노드로 삽입하기\n");	// (3)Inserting 50 node into the list as the last node
	insertLast(L, 50);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(4)리스트의 50 노드 뒤에 80 노드를 삽입하기\n");	// (4)Insert 80 node after 50 node in the list
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(5)80 노드를 검색하고 삭제하기\n");	// (5)Search for and delete 80 node
	p = search(L, 80);
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");	// No data
	else
		printf("%d 노드를 찾았습니다\n", p->data);	// Found node %d
	if(deleteNode(L, p))
		printf("노드 삭제 성공!\n");	// Delete node successful
	else
		printf("노드 삭제 실패!\n");	// Failed to delete node
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the lis
	
	printf("\n(6)10 노드 뒤에 30 노드 삽입하기\n");	// (6)Inserting 30 node after 10 node
	p = search(L, 10);
	insert(L, p, 30);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	printf("\n(7)5 노드를 검색하고 삭제하기\n");	// (7)To search for and delete 5 node
	p = search(L, 5);
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");	// No data
	else
		printf("%d 노드를 찾았습니다\n", p->data);	// Found node %d
	if (deleteNode(L, p))
		printf("노드 삭제 성공!\n");	// Delete node successful
	else
		printf("노드 삭제 실패!\n");	// Failed to delete node
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));	// Number of data stored in the list
	
	return 0;
}

