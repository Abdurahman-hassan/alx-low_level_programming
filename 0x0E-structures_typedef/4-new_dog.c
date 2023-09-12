#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new instance of the dog structure.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner's name of the dog.
 * Description:
 * This function is designed to dynamically allocate memory to create a
 * new instance of the 'dog_t' structure. It also handles memory allocation
 * for the name and owner strings, ensuring a deep copy is made. In the event
 * of any memory allocation failure, it ensures no memory leaks occur.
 * Return:
 * On success, it returns a pointer to the newly created dog_t structure.
 * On failure, it returns NULL.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	/* Pointer to the new 'dog_t' structure */
	dog_t *ptr;

	/* Dynamically allocate memory for the new 'dog_t' structure */
	ptr = malloc(sizeof(dog_t));

	/* If memory allocation for the struct failed, return NULL */
	if (ptr == NULL)
		return (NULL);

	/* Dynamically allocate memory to store the dog's name.*/
	/* We add +1 to account for the null-terminator at the end of strings*/
	ptr->name = malloc(strlen(name) + 1);

	/* If memory allocation for the name string failed,*/
	/*clean up and return NULL */
	if (!ptr->name)
	{
		free(ptr);
		return (NULL);
	}
	strcpy(ptr->name, name);
	/*
	 * Dynamically allocate memory to store the owner's name.
	 * Again, we add +1 to account for the null-terminator at the end of strings.
	 */
	ptr->owner = malloc(strlen(owner) + 1);
	/* If memory allocation for the owner string failed,*/
	/* clean up and return NULL */
	if (!ptr->owner)
	{
		free(ptr->name);
		free(ptr);
		return (NULL);
	}
	strcpy(ptr->owner, owner);
	/* Store the provided age value into the 'age' attribute of the structure */
	ptr->age = age;
	/* Successfully return the pointer to the newly created 'dog_t' structure */
	return (ptr);
}
