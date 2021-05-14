#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	if (bt1->left != NULL) {
		free(bt1->left);
	}
	bt1->left = bt2;
}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
	if (bt1->right != NULL) {
		free(bt1->right);
	}
	bt1->right = bt2;
}

// bt의 왼쪽 서브트리를 반환, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {
	return bt->left;
}

// bt의 오른쪽 서브트리를 반환, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {
	return bt->right;
}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->key = x;
}

// bt의 root에 저장된 데이터를 반환, returns data stored in bt's root
BTData getData(BinTree* bt) {
	if (bt == NULL) {
		return -1;
	}
	return bt->key;
}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// 중위 순회, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt == NULL) {
		return;
	}

	InorderTraverse(bt->left, action);
	action(bt->key);
	InorderTraverse(bt->right, action);
}

// 데이터 x가 저장된 노드 탐색, searching nodes where data x is stored
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	
	while (p != NULL) {
		if (x == p->key) return p;
		if (x < p->key) p = p->left;
		else p = p->right;
	}
	
	printf("ERROR: NO KEY FOUND\n");
	return NULL;
}

// 데이터 x 저장, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// 삽입할 노드 탐색, searching nodes to insert
	while (p != NULL) {
		if (x == p->key) {
			return;
		}
		if (x < p->key) {
			parent = p;
			p = p->left;
		}
		else {
			parent = p;
			p = p->right;
		}
	} // end while

	// 삽입할 노드 생성, create node to insert
	BinTree* newNode = createBT();
	setData(newNode, x);

	// 삽입 노드 연결, connect insert node
	if (parent == NULL) {
		bt = newNode;
	}

	else if (x < parent->key) {		// 작으면 왼쪽 
		parent->left = newNode;
	}
	
	else {							// 크면 오른쪽
		parent->right = newNode;
	}
}

// 데이터 x 노드 삭제, delete data x node
void deleteBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;
		
	// 삭제할 노드가 없는 경우, if there are no nodes to delete
	while ((p != NULL) && (p->key != x)) {
		parent = p;
		if (p == NULL) {	// 끝
			return;
		}
		if (x < p->key) {	// 작으면 왼쪽
			p = p->left;
		}
		else {				// 크면 오른쪽
			p = p->right;
		}
	}


	// CASE 1: 삭제할 노드의 차수가 0인 경우, CASE 1: if the node to be deleted has a degree of 0
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent->left == p) {	// 부모 기준 삭제할 놈이 왼쪽
			parent->left = NULL;
		}
		else {						// 부모 기준 삭제할 놈 오른쪽
			parent->right = NULL;
		}
	}


	// CASE 2: 삭제할 노드의 차수가 1인 경우, CASE 2: if the node to be deleted has a degree of 1
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {		// 오른쪽
			if (parent->left = p) {
				parent->left = p->left;
			}
			else {
				parent->right = p->left;
			}
		}

		else {						// 왼쪽
			if (parent->left == p) {
				parent->left = p->right;
			}
			else {
				parent->right = p->right;
			}
		}
	}


	// CASE 3: 삭제할 노드의 차수가 2인 경우, CASE 3: if the node to be deleted has a degree of 2
	else if (p->left != NULL && p->right != NULL) {
		BinTree* q = MaxNode(p);
		p->key = q->key;
		deleteBST(p->left, q->key);		// 리프 노드까지 재귀
	}
}	

BinTree* MaxNode(BinTree* bt) {
	BinTree* result = NULL;
	BinTree* parent = NULL;
	BinTree* p = bt->right;		// 오른쪽 서브트리 기준 후계자 탐색

	while (p != NULL) {
		parent = result;
		result = p;
		p = p->left;
	}

	if (p != bt->right) {
		parent->left = result->right;
		result->right = bt->right;
	}
	return result;
}
