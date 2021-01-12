#ifndef MAIN_H_
#define MAIN_H_
#define SIZE1 4
typedef struct {
	int mat[SIZE1][SIZE1];
	int rowWithOneCounter;
	int zeroCounter[SIZE1];
} DMatrix;

void Init(int size, DMatrix* A);
void Flip(DMatrix* A, int i, int j,int size);
int dnf(DMatrix *A);
void printDMat(DMatrix* A, int size);
void freeMat(DMatrix* DMatrix, int size);
#endif /* MAIN_H_ */