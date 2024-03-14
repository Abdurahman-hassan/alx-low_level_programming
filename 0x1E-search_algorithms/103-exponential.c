#include "search_algos.h"

/**
 * binary_search2 - searches for a value in a sorted array of integers using
 * the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @value: value to search for
 * @start: starting index
 * @end: ending index
 * Return: the first index where value is located, or -1 on failure
 */
int binary_search2(int *array, int value, size_t start, size_t end)
{
	size_t i;
	int mid;

	if (array == NULL)
		return (-1);
	while (start <= end)
	{
		printf("Searching in array: ");
		for (i = start; i < end; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		mid = (start + end) / 2;
		if (array[mid] < value)
			start = mid + 1;
		else if (array[mid] > value)
			end = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
/**
 * exponential_search - searches for a value in a sorted array of integers usin
 * the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located, or -1 on failure
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t i, bound;

	if (array == NULL)
		return (-1);
	if (size == 0)
		return (-1);
	if (array[0] == value)
		return (0);
	i = 1;
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}
	bound = i < size - 1 ? i : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", i / 2, bound);
	return (binary_search2(array, value, i / 2, bound));
}
