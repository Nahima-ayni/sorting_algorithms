#include "sort.h"

/**
 * selection_sort - function for selection sort
 * @array: the array
 * @size - number of elements
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t minIndex;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		swap(&array[i], &array[minIndex]);
		print_array(array, size);
	}
}

/**
 * swap - function to swap elements
 * @a: first paramater
 * @b: second paramater
 *
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
