#include <stdio.h>
#include <stdlib.h>


char *makenumintohexadecimal(int num){ 
	char dig2;
	int dig1;
	char* s = (char*)malloc(0);
	if (num == 0)
	{ 
		char*s = (char *)malloc(1);
		*s = '\0';
		return s;
	}
	dig1 = num % 16;
	if (dig1 < 9)
		dig2 = (char)((dig1) + 48);
	else
		dig2 = (char)((dig1)+55);

	s = makenumintohexadecimal(num/16);
	s = (char *)realloc(s, strlen(s) + 2);
	int len = strlen(s);
	*(s + len) = dig2;
	*(s + len + 1) = '\0';

	return s;
}
void main() {
	int num, x;
	printf("insert a number:\n"); 
	scanf("%d", &num);
	printf("%s", makenumintohexadecimal(num)); 
	scanf("%d", &x); 
	
}