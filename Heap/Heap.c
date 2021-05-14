#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include <math.h>

// 공백 힙 생성, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	return h;
}	

// 힙이 공백인지 검사, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}	

// 힙의 적당한 위치에 원소 x 삽입, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if(h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}
	
	int idx = h->numOfData+1;
	
	while (idx != 1) {
		if (x < h->heap[idx / 2]) {		// 삽입할 노드가 우선순위가 높으면
			h->heap[idx] = h->heap[idx / 2];	// 부모 강등
			idx = idx / 2;						// 새 노드 승급
		}
		else {	// 삽입할 노드가 우선순위가 낮으면
			break;
		}
	}

	h->heap[idx] = x;
	h->numOfData++;
}

// 힙에서 키 값이 가장 작은 원소 삭제하고 반환, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if(isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	
	HData item = h->heap[1];
	HData lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;
	
	while (childIdx <= h->numOfData) {
		
		if ((childIdx < h->numOfData) && (h->heap[childIdx] > h->heap[childIdx + 1])) {	// 우선순위 비교
			childIdx++;
		}

		if (lastVal <= h->heap[childIdx]) {	// 마지막 노드 우선순위 비교	
			break;
		}

		else {	
			h->heap[parentIdx] = h->heap[childIdx];		// 비교 노드 한 레벨 승급
			parentIdx = childIdx;						// 마지막 노드의 위치정보를 한 레벨 강등
			childIdx = childIdx * 2;
		}
	}	// end while

	h->heap[parentIdx] = lastVal;
	h->numOfData--;

	return item;
}			

// 부모 노드의 인덱스 값 반환, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx/2;
}	

// 왼쪽 자식 노드의 인덱스 값 반환, returns index value of left child node
int getLChildIdx(int idx) {
	return idx*2;
}

// 오른쪽 자식 노드의 인덱스 값 반환, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx*2+1;
}

void displayHeap(Heap* h) {
	int i;
	for(i=1; i<=h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}	
