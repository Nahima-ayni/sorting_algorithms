#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size)

/**********additional functions*****************/
void swap(int *a, int *b);
void swap_list(listint_t *a, listint_t *b);
int LargestKnuthGap(int n);
void reduceGap(int *gap);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void merge(int *array, size_t left_half, size_t right_half);
void max_heap(int *array, size_t size);
void heapify(int *array, int i, size_t heapSize);

#endif
