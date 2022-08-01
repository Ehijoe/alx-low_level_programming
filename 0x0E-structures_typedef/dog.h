#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A struct for storing info about a dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The name of the owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for dog struct
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
unsigned int _strlen(char *s);
void _strcpy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
