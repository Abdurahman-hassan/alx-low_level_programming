#include <stdio.h>

void before_main(void) __attribute__((constructor));

/**
 * before_main - A function to be executed before the main function.
 * This function is decorated with the `constructor` attribute, ensuring
 * that it will run before any `main` function in the program.
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
