#include <stdlib.h>

#include "hash_tables.h"


/**
 * free_bucket - Frees a bucket of a hash table
 * @bucket: Pointer to the first bucket of the node
 */
void free_bucket(hash_node_t *bucket)
{
	if (bucket == NULL)
		return;

	free_bucket(bucket->next);
	free(bucket->key);
	free(bucket->value);
	free(bucket);
}


/**
 * hash_table_delete - Deletes a hash table
 * @ht: Hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		free_bucket(ht->array[i]);
	}
	free(ht->array);
	free(ht);
}
