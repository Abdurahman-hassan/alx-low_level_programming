#include "3-calc.h"

/**
 * main - program that performs basic arithmetic operations.
 * desired arithmetic operation on them. The function uses function pointers
 * to dynamically choose the operation based on the user's input.
 * @arg_count: number of arguments.
 * @arg_list: array of arguments.
 * Return: Always 0 (Success).
 */
int main(int arg_count, char *arg_list[])
{
	int first_num, second_num, computed_result;
	char operation_symbol;
	int (*operation_function)(int, int);

	if (arg_count != 4)
	{
		printf("Error\n");
		exit(98);
	}

	first_num = atoi(arg_list[1]);
	second_num = atoi(arg_list[3]);

	operation_function = get_op_func(arg_list[2]);

	if (!operation_function)
	{
		printf("Error\n");
		exit(99);
	}

	operation_symbol = *arg_list[2];

	if ((operation_symbol == '/' || operation_symbol == '%') && second_num == 0)
	{
		printf("Error\n");
		exit(100);
	}

	computed_result = operation_function(first_num, second_num);

	printf("%d\n", computed_result);

	return (0);
}
