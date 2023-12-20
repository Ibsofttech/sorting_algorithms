#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void insertion_sort_element(listint_t **list, listint_t *element);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void sort_func(int *array, int upper_b, int lower_b, int size);
void swap_func(int *ele1, int *ele2);
int partition_func(int *array, int upper_b, int lower_b, int size);
void shell_sort(int *array, size_t size);
int get_element(int *array, int size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_function(int *subarr, int *new_array, size_t low_b, size_t up_b);
void merge_function(int *subarr, int *new_array, size_t low_b, size_t mid, size_t up_b);
void mx_heap(int *array, size_t lower, size_t upper, size_t size);
void heap_sort(int *array, size_t size);

#endif
