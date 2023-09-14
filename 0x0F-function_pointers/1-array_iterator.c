#include"function_pointers.h"
#include <stddef.h>

/**
  * array_iterator - function that executes a function
  * given as a parameter on each element of an array.
  * @array: An elements of array
  * @size: the size of array
  * @action: the pointer to function that we need to use
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	/* check if array && action != NULL */
	if (array && action)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
