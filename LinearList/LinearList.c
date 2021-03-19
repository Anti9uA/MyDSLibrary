// LinearList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define BUFSIZ 20
#include <stdio.h>

typedef int element;
typedef struct {
	int list[BUFSIZ];
	int length;
} ArrayList;

void init(ArrayList* L);
void insertFirst(ArrayList* L, element item);
void insertLast(ArrayList* L, element item);
void insert(ArrayList* L, int pos, element item);
element delete(ArrayList* L, int pos);
int getLength(ArrayList* L);
int isEmpty(ArrayList* L);
int isFull(ArrayList* L);
void Display(ArrayList* L);

// main
int main()
{
	// some test code...
}

void init(ArrayList* L) {	// initialize data to 0
	L->length = 0;
}

void insertFirst(ArrayList* L, element item) {
	L->list[0] = item;
	L->length++;
}

void insertLast(ArrayList* L, element item) {
	L->list[getLength(L)] = item;
	L->length++;
}

void insert(ArrayList* L, int pos, element item) {
	int i;
	if (isFull(L)) {	// is list full?
		printf("List is Full!!\n");
	}

	else if ((pos < 0) || (pos > L->length)) {	// is proper spot?
		printf("Index Error!\n");
	}

	else {
		for (i = (L->length - 1); i >= pos; i--) {	// make empty spot
			L->list[i + 1] = L->list[i];
		}
		L->list[pos] = item;	// insert data
		L->length++;	// length++
	}
}

element delete (ArrayList* L, int pos) {
	int i;
	element item;	// is list empty?
	if (isEmpty(L)) {
		printf("List is empty!!\n");
	}

	else if ((pos < 0) || (pos >= L->length)) {	// is proper spot?
		printf("Index Error!\n");
	}

	else {	// delete data
		item = L->list[pos];	// data backup
		for (i = pos; i < L->length - 1; i++) {	// pointer connect
			L->list[i] = L->list[i + 1];
		}
		L->length--;	// length--;
		return item;
	}
}

int getLength(ArrayList* L) {
	return L->length;
}

int isEmpty(ArrayList* L) {	// empty => 1, not empty => 0
	return L->length == 0;
}

int isFull(ArrayList* L) {	// full => 1, not full => 0
	return L->length == BUFSIZ;
}

void Display(ArrayList* L) {
	printf("==== Print List ====");
	for (int i = 0; i < getLength(L); i++) {
		printf("\nArrayList[%d]: %d", i, L->list[i]);
	}
}