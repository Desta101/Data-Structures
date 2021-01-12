#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{

	int numSoldiers = 0;
	int skip = 0;

	printf("\n");
	printf("Please enter the number of soldiers : \n");
	scanf("%d", &numSoldiers);

	printf("Please enter the skip number :\n");
	scanf("%d", &skip);

	insertList(numSoldiers, skip);
}