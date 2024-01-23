#include "sort.h"

/**
 * swap - function to swap
 * @a: first parameter
 * @b: second parameter
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - function to heapify
 * @array: pointer
 * @i: root, the first one
 * @heapSize: the size of the heap
 * @size: size of the array
 */
void heapify(int *array, int i, size_t heapSize, size_t size)
{
	int largest = i;
	size_t left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < heapSize && array[left] > array[largest])
		largest = left;
	if (right < heapSize && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, largest, heapSize, size);
	}
}

/**
 * heap_sort - function to sort the heap
 * @array: pointer
 * @size: unsigned integer
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	
	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, i, size, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, 0, i, size);
	}
}
