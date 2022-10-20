#include <stdlib.h>

#include "hash_tables.h"


/**
 * key_index - Return the index for a key in the hash table
 * @key: The key
 * @size: The size of the hash table
 *
 * Return: The index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
