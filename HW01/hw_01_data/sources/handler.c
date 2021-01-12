#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/handler.h"
#include "../headers/functions.h"
#include "../headers/arrays.h"

void q1()
{
    char list1[] = "hlohwaeyu";
    char list2[] = "el o r o !";
    int m = sizeof(list1) / sizeof(list1[0]);
    int n = sizeof(list2) / sizeof(list2[0]);
    char list3[n + m];
    merge_lists(list1, list2, list3, m, n);
    printf("List1:\n");
    print_char_array(list1, m);
    printf("List2:\n");
    print_char_array(list2, m);
    printf("Merged List:\n");
    print_char_array(list3, m + n);
}

void q4()
{
    int num;
    printf("Please enter a decimal number to change to binary:\n");
    scanf("%d", &num);
    printf("binary of %d = %d\n", num, decimal_base_to_binary_base(num));
}

void q5()
{
    int num, base;
    char* str = (char*) malloc (0);
    printf("Please enter a decimal number to change to a specific base: ");
    scanf("%d", &num);
    printf("Please enter the base you want to convert the decimal number to: ");
    scanf("%d", &base);
    str = decimal_base_to_any_base(num, base, str);
    printf("hexdecimal of %d = %s", num, str);
    free(str);
    
}

void q6()
{
    int arr[5];
    int size = 5, num, res;
    printf("Please enter %d numbers to popluate the array (ascending order)\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }
    printf("Please enter a number you wish to find the index for in the array\n");
    scanf("%d", &num);
    res = trinary_search(arr, size, num);
    if (res == -1)
    {
        printf("%d does not exist in the array", num);
    }
    else 
    {
        printf("%d is in the array at position %d", num, res);
    }
}

void q8()
{
    int num;
    printf("Please choose a number to print it's binary matrix: ");
    scanf("%d", &num);
    build_binary_matrix(num);
}

void q9()
{
    int n, b;
    printf("Please enter the length of the group (n): ");
    scanf("%d", &n);
    printf("Please enter the size of the group (b): ");
    scanf("%d", &b);
    build_matrix(n, b);
}