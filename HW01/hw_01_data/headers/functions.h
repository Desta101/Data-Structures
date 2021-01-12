#ifndef __FUNCTIONS__
#define __FUNCTIONS__

void merge_lists(char* list1, char* list2, char* list3, const int m, const int n);
int decimal_base_to_binary_base(int num);
char* decimal_base_to_any_base(int num, const int base, char* str);
int trinary_search(int* arr, int size, int num);
void build_binary_matrix(const int n);
void bin(int* arr, const int size, int index);
void build_matrix(const int n, const int b);
void TR8(int* arr, const int size, const int b, int index);

#endif