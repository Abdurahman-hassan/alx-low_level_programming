#include"function_pointers.h"

/**
  * print_name - function that prints a name.
  * @name: the text that will print
  * @f: the pointer function that take the function
  * and the function may print the text as it is or in upper case
  */
void print_name(char *name, void (*f)(char *))
{
	/* to check name and f in not NULL */
	/* we can use another way */
	/* if name != NULL && f != NULL */
	if (name && f)
		f(name);
}
