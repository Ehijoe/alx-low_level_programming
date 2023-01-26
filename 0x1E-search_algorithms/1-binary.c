#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Print an array
 * @array: Pointer to the array
 * @start: First element to print
 * @stop: Last element to print
 */
void print_array(int *array, size_t start, size_t stop)
{
	size_t i = 0;

	if (start > stop)
		return;
	printf("Searching in array: ");
	for (i = start; i < stop; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[stop]);
}

/**
 * binary_search_sub - Search a sorted subarray for a value
 * @array: Pointer to the array
 * @start: Index of subarray start
 * @stop: Index of subarray end (last element)
 * @value: The value to search for
 *
 * Return: The index of the first occurrence.
 *         -1 if the value is not found or array is NULL
 */
int binary_search_sub(int *array, size_t start, size_t stop, int value)
{
	size_t mid;

	if (start > stop)
		return (-1);
	print_array(array, start, stop);
	mid = (start + stop) / 2;
	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		return (binary_search_sub(array, mid + 1, stop, value));
	else
		return (binary_search_sub(array, start, mid - 1, value));
}

/**
 * binary_search - Search a sorted array for a value
 * @array: Pointer to the array
 * @size: Size of the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence.
 *         -1 if the value is not found or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (binary_search_sub(array, 0, size - 1, value));
}
