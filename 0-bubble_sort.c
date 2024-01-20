#include "sort.h"

/**
 * bubble_sort - function to implement bubble sort
 * @array: The array to be sorted.
 * @size: number of elements in the array
 * Return: void, nothing to return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
