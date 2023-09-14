#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - Selects the correct function to perform the operation.
 * @s: Operator passed as argument to the program.
 *
 * Return: Pointer to the function corresponding to the operator.
 */
int (*get_op_func(char *s))(int, int)
{
	/* ops is an array of structures containing operator strings */
	/* and their associated functions.*/
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		/* Sentinel value indicating the end of the array. */
		{NULL, NULL}
	};
	int i = 0;

	/* Iterate over each structure in the ops array */
	while (ops[i].op)
	{
		/* *s refers to the first character */
		/* of the passed operator string. */
		/* *(ops[i].op) refers to the first character */
		/* of the current operator in the ops array. */
		/* We're comparing them to see if they match. */
		/* !s[1] checks if the second character of the string */
		/* is NULL (or the end of the string). */
		/* This ensures that the string 's' contains */
		/* only one character, which is the operator. */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);  /* Return the matching function */
		i++;
	}
	/* If no matching operator was found in the ops array, */
	/* return NULL. */
	return (NULL);
}
