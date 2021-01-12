#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 



#define N  8
#define BOARD_SIDE 8
#define DIAG (N*2 - 1)
void SolutionsFinder(int board[N], int column, bool used[3][DIAG], int solutions[92][8]);
void SolutionAdd(int board[N], int size, int solutions[92][8]);
void UsedAdd(bool used[3][DIAG], int row, int column);
void UsedRemove(bool used[3][DIAG], int row, int column);
bool Legal(bool used[3][DIAG], int row, int column);
void print_sol_line(int line, int solutions[92][8]);

int main() {
	int board[N];
	bool used[3][DIAG]; // row, up-diag, down-diag

	for (int i = 0; i < DIAG; i++) {
		used[0][i] = used[1][i] = used[2][i] = false;
	}

	int solutions[92][8];
	SolutionsFinder(board, 0, used, solutions);
	int rounds,Q_col, Q_row;;
	printf("The number of times a queen enters\n");
	scanf("%d", &rounds);
	
	for (int i = 1; i <= rounds; ++i) {
		int sol_num = 1;
		printf("Choose a Column and row to enter the Queen\n");
		printf(" 1 2 3 4 5 6 7 8\n");
		printf("Row:");
		scanf("%d", &Q_row);
		printf("Col:");
		scanf("%d", &Q_col);

		for (int j = 0; j < 92; j++) {
			if (solutions[j][Q_col - 1] == Q_row) {
				if (sol_num < 10) {
					printf("");
					printf("%d    \n", sol_num);
					print_sol_line(j, solutions);
				}
				else {
					printf("%d    \n", sol_num);
					print_sol_line(j, solutions);
				}
				sol_num++;
			}
		}
		if (i + 1 != rounds)
			printf("\n");
	}
	printf("Done!\n\n");
	return 0;
};




void SolutionsFinder(int board[N], int column, bool used[3][DIAG], int solutions[92][8])
{
	if (column >= N) {
		SolutionAdd(board, N, solutions);
		return;
	}

	for (int row = 0; row < N; row++) {
		if (!Legal(used, row, column))
			continue;
		board[column] = row;
		UsedAdd(used, row, column);
		SolutionsFinder(board, column + 1, used, solutions);
		UsedRemove(used, row, column);
	}
}
bool Legal(bool used[3][DIAG], int row, int column)
{
	return  !used[0][row] && !used[1][row + column] && !used[2][N - 1 + row - column];
}

void UsedMark(bool used[3][DIAG], bool mark, int row, int column)
{
	used[0][row] = mark;
	used[1][row + column] = mark;
	used[2][BOARD_SIDE - 1 + row - column] = mark;
}

void UsedAdd(bool used[3][DIAG], int row, int column)
{
	UsedMark(used, true, row, column);
};
void UsedRemove(bool used[3][DIAG], int row, int column)
{
	UsedMark(used, false, row, column);
};

void SolutionAdd(int board[N], int size, int solutions[92][8])
{
	static int sol_num;
	for (int i = 0; i < 8; i++) {
		solutions[sol_num][i] = board[i] + 1;
	}
	sol_num++;
}
void print_sol_line(int line, int solutions[92][8]) {
	for (int i = 0; i < 8; ++i) {
		if (i < 7) {
			printf("%d  ", solutions[line][i]);
		}
		else {
			printf("%d", solutions[line][i]);
		}
	}
	printf("\n");
}

