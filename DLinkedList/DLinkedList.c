#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	if (L->head == NULL) {		// if target list is empty
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}

	else if (pre == NULL) {		// insert node to first node
		insertFirst(L, x);
	}

	else {						// insert node 
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
		}
	}

	L->length++;		// length++
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	newNode-> rlink = L->head;		 
	L->head = newNode;			// insert new node to first node
	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->rlink = NULL;
	newNode->llink = NULL;

	if (L->head == NULL) {		// if target list is empty
		L->head = newNode;
	}

	else {
		temp = L->head;
		while (temp->rlink != NULL) {	// find end node
			temp = temp->rlink;
		}
		temp->rlink = newNode;	// link last node
	}
	L->length++;
}

int deleteNode(linkedList* L, listNode* p) {
	if (L->head == NULL) { return FALSE; }	// if empty list
	if (p == NULL) { return FALSE; }	// if no node to delete
	if (p->llink == NULL) { L->head = p->llink; }	// if delete first node
	else { p->llink->rlink = p->rlink; }
	if (p->rlink != NULL) {	// if delete node is not last node
		p->rlink->llink = p->llink;
	}
	free(p);
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	while(temp != NULL) {
		if(temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

