#include <stdio.h>



int ternarySearch(int arr[], int low, int hi, int num)
{
	if (hi >= low)
	{
		int mid1 = low + (hi - low) / 3;
		int mid2 = hi - (hi - low) / 3;

		if (arr[mid1] == num)
			return mid1;
		if (arr[mid2] == num)
			return mid2;
		if (num < arr[mid1])
			return ternarySearch(arr, low, mid1 - 1, num);
		else if (num > arr[mid2])
			return ternarySearch(arr, mid2 + 1, hi, num);
		else
			return ternarySearch(arr, mid1 + 1, mid2 - 1, num);
	}
	else
		return -1;
}

int main(void)
{

	int arr[20] ;
	int result, key, size;
	int count = 0;

	printf("Enter the size of the list: ");
	scanf("%d", &size);
	printf("Enter a %d numbers to list:\n",size);
	printf("The random list:\n");
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
		printf("%d   ", arr[i]);
	}
	printf("\nEnter the key to search: ");
	scanf("%d", &key);
	result = ternarySearch(arr, 0, size, key);
	if(result == -1){
		printf("Key not found.\n");
		}
	else
		printf("Result is %d\n", result);

	return 0;
}