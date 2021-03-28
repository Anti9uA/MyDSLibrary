// Polynomial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

#define MAX_DEGREE 20

typedef struct {
	int coef;
	int degree;
}term;

void addPoly(term A[MAX_DEGREE], term B[MAX_DEGREE], term X[MAX_DEGREE]);
void printTerm(term P[MAX_DEGREE]);

int main()
{
	term A[MAX_DEGREE] = { {3,19}, {4,5}, {1,0} };
	term B[MAX_DEGREE] = { {5,3}, {7,5}, {1,1} };
	term C[MAX_DEGREE] = { 0 };
	addPoly(A, B, C);
	printf("A(x) = "); printTerm(A);
	printf("\nB(x) = "); printTerm(B);
	printf("\nC(x) = "); printTerm(C);
	return 0;
}


void addPoly(term A[MAX_DEGREE], term B[MAX_DEGREE], term X[MAX_DEGREE]) {
	int indexA = 0;
	int indexB = 0;
	int indexX = 0;

	while (!((A[indexA].degree == 0 && A[indexA].coef == 0) && (B[indexB].degree == 0 && B[indexB].coef == 0))) {
		if (A[indexA].degree > B[indexB].degree) {
		X[indexX].coef = A[indexA].coef;
		X[indexX++].degree = A[indexA++].degree;
		}

		else if (A[indexA].degree == B[indexB].degree) {
			X[indexX].coef = A[indexA].coef + B[indexB].coef;
			X[indexX++].degree = A[indexA++].degree;
			indexB++;
		}

		else {
			X[indexX].coef = B[indexB].coef;
			X[indexX++].degree = B[indexB++].degree;
		}
	}
}


void printTerm(term P[MAX_DEGREE]) {
	int i;
	if (P[0].degree == 0) {
		return;
	}
	printf("%dx^%d  ", P[0].coef, P[0].degree);
	for (i = 1; i <= MAX_DEGREE; i++) {
		if (P[i].coef == 0) {
			break;
		}
		printf("+  %dx^%d  ", P[i].coef, P[i].degree);
	}
	printf("\n");
}