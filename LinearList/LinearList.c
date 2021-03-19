// LinearList.c : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
void clear(ArrayList* L);
void replace(ArrayList* L, int pos, element item);
int isList(ArrayList* L, element item);
element getItem(ArrayList* L, int pos);
int getLength(ArrayList* L);
int isEmpty(ArrayList* L);
int isFull(ArrayList* L);
void Display(ArrayList* L);

// main
int main()
{
	
	// some test code...
	// asdfasdf

}

void init(ArrayList* L) {	// initialize data to 0
	L->length = 0;
}

void insertFirst(ArrayList* L, element item) {
	printf("Insert %d to ArrayList[0]\n", item);
	for (int i = (L->length - 1); i >= 0; i--) {	// make empty spot
		L->list[i + 1] = L->list[i];
	}
	L->list[0] = item;	// insert data
	L->length++;	// length++
}

void insertLast(ArrayList* L, element item) {
	printf("Insert %d to ArrayList[%d]\n", item, getLength(L));
	L->list[getLength(L)] = item;	// insert data to last pos
	L->length++;	// length++
}

void insert(ArrayList* L, int pos, element item) {
	if (isFull(L)) {	// is list full?
		printf("List is Full!!\n");
	}

	else if ((pos < 0) || (pos > L->length)) {	// is proper spot?
		printf("Index Error!\n");
	}

	else {
		printf("Insert %d to ArrayList[%d]\n", item, pos);
		for (int i = (L->length - 1); i >= pos; i--) {	// make empty spot
			L->list[i + 1] = L->list[i];
		}
		L->list[pos] = item;	// insert data
		L->length++;	// length++
	}
}

element delete (ArrayList* L, int pos) {
	int i;
	element item;	
	if (isEmpty(L)) {	// is list empty?
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
		L->length--;	// length--
		return item;
	}
}

void clear(ArrayList* L) {	// clear length to 0
	printf("List cleared!\n");
	L->length = 0;
}

void replace(ArrayList* L, int pos, element item) {
	if (isEmpty(L)) {	// is list empty?
		printf("List is empty!!\n");
	}

	else if ((pos < 0) || (pos > L->length)) {	// is proper spot?
		printf("Index Error!\n");
	}

	else {	// replace data
		L->list[pos] = item;
	}
}

int isList(ArrayList* L, element item) {
	for (int i = 0; i < getLength(L); i++) {	// search item
		if (L->list[i] == item) {	// search ok
			return 1;
		}
	}
	return 0;	// search failed
}

element getItem(ArrayList* L, int pos) {
	return L->list[pos];	// return item
}

int getLength(ArrayList* L) {
	return L->length;	// return length
}

int isEmpty(ArrayList* L) {	// empty => 1, not empty => 0
	return L->length == 0;
}

int isFull(ArrayList* L) {	// full => 1, not full => 0
	return L->length == BUFSIZ;
}

void Display(ArrayList* L) {
	if (isEmpty(L)) {	// is list empty?
		printf("List is empty!!\n");
	}
	else {
		printf("==== Print List ====\n");
		for (int i = 0; i < getLength(L); i++) {	// print all
			printf("ArrayList[%d]: %d\n", i, L->list[i]);
		}
	}
}