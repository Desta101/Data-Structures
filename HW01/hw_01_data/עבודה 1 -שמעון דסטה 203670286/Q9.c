#include <stdio.h>

void TR8(int* word, int size, int b, int index);
int main() {
	
	int n, b, index = 0;

	printf("Please enter the length: ");
	scanf("%d", &n);
	printf("Please enter the size: ");
	scanf("%d", &b);

	int* word = (int*)malloc(n * sizeof(int));
	TR8(word, n, b, index);
	free(word);

	return 0;
}


void TR8(int* word,  int n, int b, int index)
{
	if (n == index)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", *(word + i));
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < b; i++)
	{
		*(word + index) = i;
		TR8(word, n, b, index + 1);
	}
}

