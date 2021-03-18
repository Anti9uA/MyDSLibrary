// LinearList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define BUFSIZ 20
#include <stdio.h>

typedef int element;
typedef struct {
	int list[BUFSIZ];
	int length
} ArrayList;

void init(ArrayList* L);
int isEmpty(ArrayList* L);
int isFull(ArrayList* L);
void insert(ArrayList* L, int pos, element item);
element delete(ArrayList* L, int pos);

int main()
{


	return 0;
}

void init(ArrayList* L) {	// initialize data to 0
	L->length = 0;
}

int isEmpty(ArrayList* L) {	// empty => 1, not empty => 0
	return L->length == 0;
}

int isFull(ArrayList* L) {	// full => 1, not full => 0
	return L->length == BUFSIZ;
}

void insert(ArrayList* L, int pos, element item) {	
	int i;
	if (isFull(L)) {	// is list full?
		error("List is Full!!");
	}

	else if ((pos < 0) || (pos > L -> length)) {	// is proper spot?
		error("Index Error!");
	}

	else {
		for (i = (L->length - 1); i >= pos; i--) {	// make empty spot
			L->list[i + 1] = L->list[i];
		}
		L -> list[pos] = item;	// insert data
		L->length++;	// length++
	}
}

element delete (ArrayList* L, int pos) {
	int i;
	element item;	// is list empty?
	if (isEmpty(L)) {
		error("List is empty!");
	}

	else if ((pos < 0) || (pos >= L->length)) {	// is proper spot?
		error("Index error!");
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