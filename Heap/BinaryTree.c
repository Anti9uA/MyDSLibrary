#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	if (bt1->left != NULL) {
		free(bt1->left);
	}
	bt1->left = bt2;
}

// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
	if (bt1->right != NULL) {
		free(bt1->right);
	}
	bt1->right = bt2;
}

// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {
	return bt->left;
}

// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {
	return bt->right;
}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->key = x;
}

// bt�� root�� ����� �����͸� ��ȯ, returns data stored in bt's root
BTData getData(BinTree* bt) {
	if (bt == NULL) {
		return -1;
	}
	return bt->key;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// ���� ��ȸ, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt == NULL) {
		return;
	}

	InorderTraverse(bt->left, action);
	action(bt->key);
	InorderTraverse(bt->right, action);
}

// ������ x�� ����� ��� Ž��, searching nodes where data x is stored
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

// ������ x ����, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// ������ ��� Ž��, searching nodes to insert
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

	// ������ ��� ����, create node to insert
	BinTree* newNode = createBT();
	setData(newNode, x);

	// ���� ��� ����, connect insert node
	if (parent == NULL) {
		bt = newNode;
	}

	else if (x < parent->key) {		// ������ ���� 
		parent->left = newNode;
	}
	
	else {							// ũ�� ������
		parent->right = newNode;
	}
}

// ������ x ��� ����, delete data x node
void deleteBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;
		
	// ������ ��尡 ���� ���, if there are no nodes to delete
	while ((p != NULL) && (p->key != x)) {
		parent = p;
		if (p == NULL) {	// ��
			return;
		}
		if (x < p->key) {	// ������ ����
			p = p->left;
		}
		else {				// ũ�� ������
			p = p->right;
		}
	}


	// CASE 1: ������ ����� ������ 0�� ���, CASE 1: if the node to be deleted has a degree of 0
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent->left == p) {	// �θ� ���� ������ ���� ����
			parent->left = NULL;
		}
		else {						// �θ� ���� ������ �� ������
			parent->right = NULL;
		}
	}


	// CASE 2: ������ ����� ������ 1�� ���, CASE 2: if the node to be deleted has a degree of 1
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {		// ������
			if (parent->left = p) {
				parent->left = p->left;
			}
			else {
				parent->right = p->left;
			}
		}

		else {						// ����
			if (parent->left == p) {
				parent->left = p->right;
			}
			else {
				parent->right = p->right;
			}
		}
	}


	// CASE 3: ������ ����� ������ 2�� ���, CASE 3: if the node to be deleted has a degree of 2
	else if (p->left != NULL && p->right != NULL) {
		BinTree* q = MaxNode(p);
		p->key = q->key;
		deleteBST(p->left, q->key);		// ���� ������ ���
	}
}	

BinTree* MaxNode(BinTree* bt) {
	BinTree* result = NULL;
	BinTree* parent = NULL;
	BinTree* p = bt->right;		// ������ ����Ʈ�� ���� �İ��� Ž��

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
