#include "sort.h"

/**
 * get_max - maximum value in an array of integers
 * @array: array of integers
 * @size: size of the array
 * Return: maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_value, i;

	for (max_value = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * counting_sort - Sort an array of integers in ascending order.
 * @array: array of integers
 * @size: size of the array
 * Description: Prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_value, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_value = get_max(array, size);
	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i < (max_value + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max_value + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
