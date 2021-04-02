#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(struct Node*));
	newNode->exp = exp;
	newNode->coef = coef;
	if (PL->head == NULL) {		// append first term
		PL->head = newNode;
		PL->last = newNode;
	}

	else {	// append next term
		PL->last->link = newNode;
		PL->last = newNode;
	}
	PL->last->link = NULL;	// last link is null
}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* polyA = A->head;
	Node* polyB = B->head;
	int sub = 0;
	while (polyA != NULL && polyB != NULL) {
		if (polyA->exp == polyB->exp) {		// if same exp
			sub = polyA->coef - polyB->coef;
			if (sub != 0) {		// if coef is not 0
				appendTerm(C, sub, polyA->exp);
			}
			polyA = polyA->link;
			polyB = polyB->link;
		}

		else if (polyA->exp > polyB->exp) {		// if polyA's exp is bigger than polyB
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;
		}

		else if (polyA->exp < polyB->exp) {		// if polyB's exp is bigger than polyA
			appendTerm(C, polyB->coef, polyB->exp);
			polyB = polyB->link;
		}
	}

	while (polyA != NULL) {		// append another term
		appendTerm(C, polyA->coef, polyA->exp);
		polyA = polyA->link;
	}

	while (polyB != NULL) {		// append another term
		appendTerm(C, polyB->coef, polyB->exp);
		polyB = polyB->link;
	}
	
	C->last->link = NULL;		// last link is null
	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for (; p; p = p->link) {
		if (p->coef > 0)
			printf("\t+");
		else
			printf("\t");
		printf("%.0fx^%d", p->coef, p->exp);
	}
	printf("\n");
}
