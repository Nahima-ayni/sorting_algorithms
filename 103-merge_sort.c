#include "sort.h"

/**
 * merge_sort - function for merge sort
 * @array: pointer
 * @size: size of the elements
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array, mid);

	printf("[right]: ");
	print_array(array + mid, size - mid);

	merge(array, mid, size - mid);

	printf("[Done]: ");
	print_array(array, size);

}

/**
 * merge - function for the merge
 * @array: pointer
 * @left_half: the first half
 * @right_half: the second half
 */
void merge(int *array, size_t left_half, size_t right_half)
{
	int *temp;
	size_t i = 0, j = 0, k = 0, n;

	temp = malloc((left_half + right_half) * sizeof(int));
	if (temp == NULL)
		return;

	while (i < left_half && j < right_half)
	{
		if (array[i] <= array[left_half + j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[left_half + j];
			j++;
		}
		k++;
	}

	while (i < left_half)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j < right_half)
	{
		temp[k] = array[left_half + j];
		j++;
		k++;
	}

	for (n = 0; n < left_half + right_half; n++)
		array[n] = temp[n];

	free(temp);
}
