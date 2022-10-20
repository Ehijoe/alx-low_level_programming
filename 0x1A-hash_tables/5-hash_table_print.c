#include <stdio.h>

#include "hash_tables.h"


/**
 * hash_table_print - Print out a hash table
 * @ht: Hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *curr;
	unsigned long int i;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (curr = ht->array[i]; curr != NULL; curr = curr->next)
		{
			if (first)
				first = 0;
			else
				printf(", ");
			printf("'%s': '%s'", curr->key, curr->value);
		}
	}
	printf("}\n");
}
