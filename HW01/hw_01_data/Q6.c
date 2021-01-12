#include <stdio.h>

int trinary_search(int[], int, int);
int main()
{
	int size, index, key;
	int list[20];
	int count = 0;
	int i;

	printf("Enter the size of the list: ");
	scanf("%d", &size);
	index = size;
	printf("The random list:\n");
	for (i = 0; i < size; i++){
		list[i] = rand() % size;
		printf("%d   ", list[i]);
	}
	printf("\nEnter the key to search: ");
	scanf("%d", &key);
	
	while (index > 0)
	{
		index = trinary_search(list, index - 1, key);
		printf("Key position is at: %d\n", index + 1);
		count++;
	}
	if (!count)
		printf("Key not found.\n");
	return 0;
}
int trinary_search(int array[], int size, int key)
{
	int tmep;
	if (array[size] == key)
	{
		return size;
	}
	else if (size == -1)
	{
		return -1;
	}
	else
	{
		return (tmep = trinary_search(array, size - 1, key));
	}
}