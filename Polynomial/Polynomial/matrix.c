#include <stdio.h>

typedef struct {
	int row, col, value;
} matrix;

void transpose(matrix a[], matrix b[]);

int main()
{
	matrix a[11] = {
		{8,7,10},
		{0,2,2},
		{0,6,12},
		{1,4,7},
		{2,0,23},
		{3,3,31},
		{4,1,14},
		{4,5,25},
		{5,6,6},
		{6,0,52},
		{7,4,11},
	};

	matrix b[11] = { 0, };
	transpose(a, b);

	printf("Matrix a\n");
	for (int i = 0; i < 11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for (int i = 0; i < 11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}

void transpose(matrix a[], matrix b[]) 
{
	int  n, i, j, current;
	n = a[0].value;	
	b[0].row = a[0].col;	// row of b = col of a
	b[0].col = a[0].row;    // col in b = row of a 
	b[0].value = n;
	if (n > 0) {
		current = 1;
		for (int i = 0; i < a[0].col; i++) // transpose by the col of a 
			for (int j = 1; j <= n; j++)	// find elements of a in col i
				if (a[j].col == i) {
					b[current].row = a[j].col;
					b[current].col = a[j].row;
					b[current].value = a[j].value;
					current++;
				}
	}
}