#include"function_pointers.h"

/**
  * print_name - function that prints a name.
  * @name: the text that will print
  * @f: the pointer function that take the function
  * and the function may print the text as it is or in upper case
  */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
