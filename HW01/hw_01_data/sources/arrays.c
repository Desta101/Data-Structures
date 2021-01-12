#include <stdio.h>

#include "../headers/arrays.h"

void print_int_array(const int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void print_char_array(const char* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", *(arr + i));
    }
    printf("\n");
}

int find_needed_array_size_for_new_base(int num, const int base)
{
    int count = 1;
    while (num / base != 0)
    {
        count++;
        num /= base;
    }
    return count;
}

void populate_char_array_with_zeros(char* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = '0';
    }
}

void populate_int_array_with_zeros(char* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = '0';
    }
}

int sum_array(int* arr, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}