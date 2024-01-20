#include "sort.h"

/**
 *quick_sort - unction that sorts an array of integers in ascending order
 *@array: data to be sorted
 *@size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function to perform the Quicksort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index of the array or subarray.
 * @high: The ending index of the array or subarray.
 */
void quicksort_recursive(int *array, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pivot = partition(array, low, high);

		if (pivot != 0)  /* Check to avoid underflow */
			quicksort_recursive(array, low, pivot - 1);
		quicksort_recursive(array, pivot + 1, high);
	}
}


/**
 *partition - lumoto partition
 *@arr: array
 *@low: lowest index
 *@high: highest index
 *Return: integer
 */
int partition(int arr[], size_t low, size_t high)
{
	int pivot = arr[high];
	size_t i = low - 1;
	size_t j;
	size_t k = high + 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array((const int *)arr, k);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	print_array((const int *)arr, k);
	return (i + 1);
}

/**
 * swap - swapping
 * @a: variable
 * @b: variable
 */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
