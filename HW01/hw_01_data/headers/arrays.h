#ifndef _ARRAYS__
#define __ARRAYS__

void print_int_array(const int* arr, const int size);
void print_char_array(const char* arr, const int size);
void populate_char_array_with_zeros(char* arr, const int size);
void populate_int_array_with_zeros(char* arr, const int size);
int find_needed_array_size_for_new_base(int num, const int base);
int sum_array(int* arr, const int size);

#endif