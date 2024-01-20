#include "sort.h"

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
