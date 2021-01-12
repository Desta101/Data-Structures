#include <stdio.h>
#include "main.h"

int main(int argc, char **argv) {
	DMatrix A;
	int num,size;
	printf("Enter a size of matrix \n");
	scanf_s("%d", &size);
	Init(size, &A);
	

	do
	{
		printf("----------Menu:-----------\n");
		printf("Enter a number between 1 to 3:\n");
		printf("1 - flip by row and col\n");
		printf("2 - check if matrix dnf\n");
		printf("3 - Exit\n");
		scanf_s("%d", &num);
		printf("\n");

		switch (num) {
		case 1: {
			int row, col;

			printf("Enter a row: ");
			do {
				scanf_s("%d", &row);

				if (row < 0 || row >= size)
					printf("Wrong size, Entar size row between 0 to %d: ", (size - 1));
			} while (row < 0 || row >= size);

			printf("Enter a col: ");
			do {
				scanf_s("%d", &col);

				if (col < 0 || col >= size)
					printf("Wrong size, Entar size col between 0 to %d: ", (size - 1));
			} while (col < 0 || col >= size);

			Flip(&A, row, col, size);
			printDMat(&A, size);
			break;
		}
		case 2: {
			printf("the dnf is %d\n", dnf(&A));
			break;
		}
		case 3: {
			freeMat(&A, size);
			printf("Bye!\n");
			break;
		}
		default:
			printf("Wrong Number!\n");
			printf("Enter a number between 1 to 3:\n");
			break;
		}
	} while (num != 4);
	return 1;
}

void Init(int size, DMatrix* A) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			A->mat[i][j] = 1;
		}
		A->zeroCounter[i] = 0;
	}
	A->rowWithOneCounter = size;
}

void Flip(DMatrix* A, int i, int j,int size) {
	if (i < 0 || size <= i || j < 0 || size <= j) {
		printf("The requested i and j is not in the matrix\n");
		return;
	}
	if (A->mat[i][j] == 1) {
		A->mat[i][j] = 0;
		if (A->zeroCounter[i] == 0)
			A->rowWithOneCounter--;
		A->zeroCounter[i]++;
	} else {
		A->mat[i][j] = 1;
		A->zeroCounter[i]--;
		if (A->zeroCounter[i] == 0)
			A->rowWithOneCounter++;
	}
}

int dnf(DMatrix* A) {
	if (A->rowWithOneCounter == 0)
		return 0;
	else
		return 1;
}

void printDMat(DMatrix* A, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d ", A->mat[i][j]);
		}
		printf("\n");
	}
}
void freeMat(DMatrix* A, int size)
{
	for (int i = 0; i < size; i++) {
			free(A->mat[i]);
	}
	free(A->mat);
	free(A->rowWithOneCounter);
	free(A);
}