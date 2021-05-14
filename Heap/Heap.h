#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef int HData;

typedef struct {
	HData heap[MAX_SIZE];
	int numOfData;
}Heap;

Heap* createHeap();					// 공백 힙 생성, create a empty heap
int isEmpty(Heap* h);				// 힙이 공백인지 검사, check if heap is empty
void insertHeap(Heap* h, HData x);	// 힙의 적당한 위치에 원소 x 삽입, insert element x in appropriate position on heap
HData deleteHeap(Heap* h);			// 힙에서 키 값이 가장 작은 원소 삭제하고 반환, delete the element with the smallest key value from the heap and return it

int getParentIdx(int idx);			// 부모 노드의 인덱스 값 반환, returns the index value of the parent node
int getLChildIdx(int idx);			// 왼쪽 자식 노드의 인덱스 값 반환, returns index value of left child node
int getRChildIdx(int idx);			// 오른쪽 자식 노드의 인덱스 값 반환, returns index value of right chlid node
void displayHeap(Heap* h);

#endif
