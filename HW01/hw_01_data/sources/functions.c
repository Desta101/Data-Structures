#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/functions.h"
#include "../headers/arrays.h"

void merge_lists(char* list1, char* list2, char* list3, const int m, const int n)
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

int decimal_base_to_binary_base(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return decimal_base_to_binary_base(num / 2) * 10 + num % 2;
}

char* decimal_base_to_any_base(int num, const int base, char* str)
{
    char dig;
    if (num == 0)
    {
        str = (char*) malloc(1 * sizeof(char));
        *str= '\0';
        return str;
    }
    if (num % base <= 9)
    {
        dig = (char)((num % base) + 48);
    }
    else
    {
        dig = (char)((num % base) + 55);
    }
    str = decimal_base_to_any_base(num / base, base, str);
    str = (char*) realloc(str, strlen(str) + 2);
    int len = strlen(str);
    str[len] = dig;
    str[len + 1] = '\0';
    return str;
}

int trinary_search(int* arr, int size, int num)
{
    if (size == 0)
    {
        return -1;
    }
    int index = size * 2 / 3;
    if (num == *(arr + index))
    {
        return index;
    }
    else if (num > *(arr + index))
    {
        int temp = trinary_search(arr + index + 1, (arr + size) - (arr + index + 1), num);
        return temp != -1 ? temp + index + 1 : temp;
    }
    index = size / 3;
    if (num == *(arr + index))
    {
        return index;
    }
    else if (num > *(arr + index))
    {
        int temp = trinary_search(arr + index + 1, (arr + (size * 2 / 3)) - (arr + index + 1), num);
        return temp != -1 ? temp + index + 1 : temp;
    }
    index = 0;
    if (num == *(arr + index))
    {
        return index;
    }
    int temp = trinary_search(arr + 1, (arr + (size / 3)) - (arr + 1), num);
    return temp != -1 ? temp + index + 1 : temp;
}

void build_binary_matrix(const int n)
{
    int* arr = (int*) malloc(n * sizeof(int));
    bin(arr, n, 0);
    free(arr);
}

void bin(int* arr, const int size, int index)
{
    if (size == index)
    {
        print_int_array(arr, size);
        return;
    }
    *(arr + index) = 0;
    bin(arr, size, index + 1);
    *(arr + index) = 1;
    bin(arr, size, index + 1);
}

void build_matrix(const int n, const int b)
{
    int* arr = (int*) malloc(n * sizeof(int));
    TR8(arr, n, b, 0);
    free(arr);
}

void TR8(int* arr, const int size, const int b, int index)
{
    if (size == index)
    {
        print_int_array(arr, size);
        return;
    }
    for (int i = 0; i < b; i++)
    {
        *(arr + index) = i;
        TR8(arr, size, b, index + 1);
    }
}