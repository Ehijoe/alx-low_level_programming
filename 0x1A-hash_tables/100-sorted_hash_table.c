#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_tables.h"


/**
 * shash_table_create - Create a php-style hash table
 * @size: The size of the hash table to create
 *
 * Return: A pointer to the hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int i;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);
	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	table->size = size;
	for (i = 0; i < size; i++)
		table->array[i] = NULL;
	table->shead = NULL;
	table->stail = NULL;
	return (table);
}

/**
 * shash_table_set - Set the value for a particular key in a hash table
 * @ht: Hash table to use
 * @key: The key
 * @value: The new value
 *
 * Return: 1 on success and 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	char *val_dup, *old;
	shash_node_t *new;
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
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	if (new->key == NULL)
		return (0);
	new->value = val_dup;
	new->next = ht->array[index];
	ht->array[index] = new;
	if (insert_sorted(ht, new))
	{
		return (1);
	}
	return (0);
}

/**
 * insert_sorted - Insert a node into a sorted hash table
 * @ht: The hash table to insert into
 * @new: The new node
 *
 * Return: 1 on success and 0 on failure
 */
int insert_sorted(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *curr;

	if (ht == NULL)
		return (0);
	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
		new->sprev = NULL;
		new->snext = NULL;
		return (1);
	}
	if (strcmp(ht->shead->key, new->key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
		return (1);
	}
	curr = ht->shead;
	while (curr != NULL && strcmp(curr->key, new->key) < 0)
		curr = curr->snext;
	if (curr == NULL)
	{
		new->snext = NULL;
		new->sprev = ht->stail;
		ht->stail->snext = new;
		ht->stail = new;
		return (1);
	}
	new->sprev = curr->sprev;
	new->snext = curr;
	curr->sprev->snext = new;
	curr->sprev = new;
	return (1);
}

/**
 * shash_table_get - Get a value from a hash table
 * @ht: Hash table to get from
 * @key: Key to search for
 *
 * Return: The value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *curr;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((unsigned char *) key, ht->size);
	for (curr = ht->array[index]; curr != NULL; curr = curr->next)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
	}
	return (NULL);
}

/**
 * shash_table_print - Print out a hash table
 * @ht: Hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	for (curr = ht->shead; curr != NULL; curr = curr->snext)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print out a hash table in reverse
 * @ht: Hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	for (curr = ht->stail; curr != NULL; curr = curr->sprev)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
	}
	printf("}\n");
}

/**
 * shash_free_nodelist - Free The list of hash nodes
 * @list: Pointer to first node
 */
void shash_free_nodelist(shash_node_t *list)
{
	if (list == NULL)
		return;
	shash_free_nodelist(list->snext);
	free(list->key);
	free(list->value);
	free(list);
}

/**
 * shash_table_delete - Delete a php-style hash table
 * @ht: Hash table to free
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;
	shash_free_nodelist(ht->shead);
	free(ht->array);
	free(ht);
}
