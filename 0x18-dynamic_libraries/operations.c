#include <stdio.h>

/**
 * add - function that adds two integers and returns the result
 *
 * @a: first number to add
 * @b: second number to add
 *
 * Return: The result of the addition
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - function that subtracts two integers and returns the result
 *
 * @a: first number to subtract
 * @b: second number to subtract
 *
 * Return: The result of the subtraction
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - function that multiplies two integers and returns the result
 *
 * @a: first number to multiply
 * @b: second number to multiply
 *
 * Return: The result of the multiplication
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - function that divides two integers and returns the result
 *
 * @a: first number to divide
 * @b: second number to divide
 *
 * Return: The result of the division
 */
int div(int a, int b)
{
	if (b != 0)
		return (a / b);
	else
		return (0);
}

/**
 * mod - function that returns the remainder of dividing two integers
 *
 * @a: first number to divide
 * @b: second number to divide
 *
 * Return: The remainder of the division
 */
int mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	else
		return (0);
}
