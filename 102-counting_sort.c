#include "sort.h"

/**
 *counting_sort - counting sort algorithm
 *@array: array
 *@size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int index, *count, j;
	int *sorted_array;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max) * sizeof(int));
	if (count == NULL)
		exit(EXIT_FAILURE);
	for (j = 0; j <= max; j++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 0; j <= max; j++)
		count[j] += count[j - 1];
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
		exit(EXIT_FAILURE);
	for (j = size - 1; j >= 0; j--)
	{
		index = count[array[j]] - 1;
		sorted_array[index] = array[j];
		count[array[j]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	print_array(count, max + 1);
	free(count);
	free(sorted_array);
}
