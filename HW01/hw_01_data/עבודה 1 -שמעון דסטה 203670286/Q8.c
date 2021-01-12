#include <stdio.h>


void print_array(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}
void bin(int word[], int n, int index)
{
	if (n == index)
	{
		print_array(word, n);
		return;
	}
	*(word + index) = 0;
	bin(word, n, index + 1);
	*(word + index) = 1;
	bin(word, n, index + 1);
}

int main(void)
{

	int num;
	printf("Please choose a number to print it's binary matrix: ");
	scanf("%d", &num);
	int* arr = (int*)malloc(num * sizeof(int));
	bin(arr, num, 0);
	free(arr);

	return 0;
}