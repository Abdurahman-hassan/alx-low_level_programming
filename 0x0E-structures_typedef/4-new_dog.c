#include "dog.h"
#include <stdlib.h>

/**
  * new_dog - function that creates a new dog.
  * @name: is the name of dog
  * @age: the age of dog
  * @owner: the name of the owner of the dog
  * Return: a pinter to a struct new_dog
  */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr;

	ptr = malloc(sizeof(dog_t));

	if (ptr == NULL)
		return (NULL);

	ptr->name = name;
	(*ptr).owner = owner;
	ptr->age = age;

	return (ptr);

}
