#include <stdlib.h>
#include <string.h>

#include "hash_tables.h"


/**
 * hash_table_get - Get a value from a hash table
 * @ht: Hash table to get from
 * @key: Key to search for
 *
 * Return: The value
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *curr;
	unsigned long int index;

	index = key_index(key, ht->size);
	for (curr = ht->array[index]; curr != NULL; curr = curr->next)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
	}
	return (NULL);
}
