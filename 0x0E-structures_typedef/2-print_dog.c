#include<stdio.h>
#include"dog.h"

/**
  * print_dog - function that prints a struct dog
  * @d: is the object of struct
  * Return: void
  */
void print_dog(struct dog *d)
{
	if (d == NULL)
		printf("nothing");
	if (d->name == NULL)
		printf("Name: (nil)\n");

	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}
