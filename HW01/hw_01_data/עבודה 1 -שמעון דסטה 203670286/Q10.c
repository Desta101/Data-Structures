#include <stdio.h>


void printArray(int *arr, int m);
void printC(int *arr, int n, int i);
int main(void)
{
	int n ;
	printf("Enter a number:\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	printC(arr, n, 0);

	return 0;
}
void printArray(int *arr, int m)
{
	for (int i = 0; i < m; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void printC(int *arr, int n, int i){
	
	if (n == 0) {
		printArray(arr, i);
	}
	else if (n > 0) {
		for (int k = 1; k <= n; k++) {
			arr[i] = k;
			printC(arr, n - k, i + 1);
		}

	}
}