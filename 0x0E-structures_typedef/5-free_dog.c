#include "dog.h"
#include<stdlib.h>

/**
  * free_dog - function that frees dogs.
  * @d: it the object of struct dog_t
  * Return: Void.
  */
void free_dog(dog_t *d)
{
	/*if d != NULL*/
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
