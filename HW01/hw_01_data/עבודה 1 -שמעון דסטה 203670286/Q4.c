#include <stdio.h>
#include <stdlib.h>

int decimal_base(int num)
{
if (num == 1)
{
return 1;
}
return decimal_base(num / 2) * 10 + num % 2;
}

int main(){

int num;
    printf("Please enter a decimal number to change to binary:\n");
    scanf("%d", &num);
    printf("binary of %d = %d\n", num, decimal_base(num));

return 0;
}