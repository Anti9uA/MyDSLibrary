#include <stdio.h>
#include "Heap.h"

int main() {
	Heap* h = createHeap();
	
	insertHeap(h, 20);
	insertHeap(h, 15);	//					8
	insertHeap(h, 19);	//			13				10
	insertHeap(h, 8);	//		20		15		19
	insertHeap(h, 13);
	insertHeap(h, 10);
	printf("\n");
	displayHeap(h);
	
	printf("(1) 5 »ğÀÔ\n");	//(1) Insert 5	//					5
	insertHeap(h, 5);						//			13				8
	displayHeap(h);							//		20		15		19		10
	
	printf("(2) 16 »ğÀÔ\n");	//(2) Insert 16	//					5
	insertHeap(h, 16);							//			13				8
	displayHeap(h);								//		16		15		19		10
												//	20
	printf("(3) Heap ¿ä¼Ò Â÷·Ê·Î »èÁ¦\n");	// (3) Delete Heap elements in turn
	while(!isEmpty(h))
		printf("%d \n", deleteHeap(h));
	// deleteHeap(h);
	// displayHeap(h);
	return 0;	
}
