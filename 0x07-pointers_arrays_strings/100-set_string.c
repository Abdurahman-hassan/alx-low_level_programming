# include "main.h"

/**
  * set_string - function that sets the value of a pointer to a char.
  * @s: pointer of pointer of char
  * @to: this pointer will be change to point to @s
  * The string that the pointer should point to after the function
  * Return: void
  */
void set_string(char **s, char *to)
{
	*s = to;
}
