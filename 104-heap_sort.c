#include "sort.h"

/**
 * * swap - swap two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - maintain the max-heap property
 * @array: array to be sorted
 * @i: root index
 * @size: size of the heap
 */
void heapify(int *array, int i, size_t size)
{
	int largest = i;
	size_t left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - function for heap sort
 * @array: pointer, array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}
