#include <stdlib.h>
#include <string.h>

#include "hash_tables.h"


/**
 * hash_table_set - Assign a value to a key in a hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value to store
 *
 * Return: 1 on success and 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *val_dup, *old;
	hash_node_t *new;
	unsigned long int index;

	if (key == NULL || ht == NULL || value == NULL || key[0] == '\0')
		return (0);
	index = key_index((unsigned char *) key, ht->size);
	val_dup = strdup(value);
	if (val_dup == NULL)
		return (0);
	for (new = ht->array[index]; new != NULL; new = new->next)
	{
		if (strcmp(new->key, key) == 0)
		{
			old = new->value;
			new->value = val_dup;
			free(old);
			return (1);
		}
	}
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	if (new->key == NULL)
		return (0);
	new->value = val_dup;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
