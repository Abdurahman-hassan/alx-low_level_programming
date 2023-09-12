#include<stdlib.h>
#include "dog.h"

/**
  * init_dog - function that initialize a variable of type struct dog
  * @d: the struct object
  * @name: name of the dog
  * @age: age of the dog
  * @owner: the name of the dog owner
  * Return: void
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	(*d).owner = owner;
}

