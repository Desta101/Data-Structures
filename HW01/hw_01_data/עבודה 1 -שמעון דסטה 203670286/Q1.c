#include <stdio.h>


void printArray(char* arr, int size);
void merge_lists(char list1[], char list2[], char list3[], int m, int n);

int main(void)
{
	char list1[] = "hlohwaeyu";
	char list2[] = "el o r o !";
	int n, m;
	m = sizeof(list1) / sizeof(list1[0]);
	n = sizeof(list2) / sizeof(list2[0]);

	char *list3 = (int*)malloc((n + m) * sizeof(int));;
	printf("List1:\n");
	printArray(list1, m);
	printf("List2:\n");
	printArray(list2, n);
	merge_lists(list1, list2, list3, m, n);
	printf("Merged List:\n");
	printArray(list3, m + n - 2);

	return 0;
}

void printArray(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", *(arr + i));
	}
	printf("\n");
}

void merge_lists(char list1[], char list2[], char list3[], int m, int n)
{
	if (m != 1)
	{
		*list3 = *list1;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			*(list3 + i) = (*list2 + i);
		}
		return;
	}
	if (n != 1)
	{
		*(list3 + 1) = *list2;
	}
	else
	{
		for (int i = 0; i < m - 1; i++)
		{
			*(list3 + i) = *(list1 + i);
		}
		return;
	}
	merge_lists(list1 + 1, list2 + 1, list3 + 2, m - 1, n - 1);
}

