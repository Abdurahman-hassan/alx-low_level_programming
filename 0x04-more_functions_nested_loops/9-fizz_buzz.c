#include <stdio.h>

/**
  * main - This is the start point of the program.
  * In the main function, we will print the numbers from 1 to 100
  * followed by a new line. But for multiples of three print Fizz
  * instead of the number, and for multiples of five print Buzz.
  * For numbers which are multiples of both three and five print FizzBuzz.
  * Return: 0 if success.
  */
int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 3 == 0 && num % 5 != 0)
			printf("Fizz");
		else if (num % 5 == 0 && num % 3 != 0)
			printf("Buzz");
		else if (num % 3 == 0 && num % 5 == 0)
			printf("FizzBuzz");
		else
			printf("%d", num);

		if (num != 100)
			printf(" ");
		else
			printf("\n");
	}
	return (0);
}

