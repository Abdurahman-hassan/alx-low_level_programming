#include"3-calc.h"

/**
  * op_add - this function add two numbers
  * @a: is the first number
  * @b: is the second number
  * Return: sum of a and b
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - this function difference two numbers
  * @a: is the first number
  * @b: is the second number
  * Return: difference of a and b
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - this function product two numbers
  * @a: is the first number
  * @b: is the second number
  * Return: product of a and b
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - this function division two numbers
  * @a: is the first number
  * @b: is the second number
  * Return: division of a and b
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - this function remainder two numbers
  * @a: is the first number
  * @b: is the second number
  * Return: remainder of a and b
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
