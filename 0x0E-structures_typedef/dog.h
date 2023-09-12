#ifndef DOG_H
#define DOG_H


/**
  * struct dog - for dog description
  * @name: the name of dog
  * @age: the age of dog
  * @owner: the name of the owner of the dog
  */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

typedef struct dog dog_t;
#endif
