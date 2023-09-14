#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation.
 * @s: Operator passed as argument to the program.
 *
 * Return: Pointer to the function corresponding to the operator.
 */
int (*get_op_func(char *s))(int, int)
{
	/* Initialize an array of structures 'ops', where each element represents */
	/* an arithmetic operation and its corresponding function. */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}  /* The end-marker for our array. */
	};
	int i = 0;

	/* Traverse the 'ops' array to find a matching operation. */
	while (ops[i].op)
	{
		/* Check if the passed operator matches with the current */
		/* operation in our 'ops' array. */
		/* If a match is found, return its associated function. */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
		i++;
	}

	/* If loop completes without finding a match, return NULL. */
	return (NULL);
}

