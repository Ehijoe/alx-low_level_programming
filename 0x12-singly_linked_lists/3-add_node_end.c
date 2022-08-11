#include "lists.h"
#include <string.h>

/**
 * _strlen - Gets the length of a string
 * @s: The string whose length to find
 *
 * Return: The length of s
 */
int _strlen(const char *s)
{
	if (s == NULL)
	{
		return (0);
	}
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen(s + 1));
}

/**
 * add_node_end - Adds a node to the end of the list
 * @head: A pointer to the list(The list is a pointer to the first node)
 * @str: The string to store in the node
 *
 * Return: The address of the new node or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *curr;

	if (head == NULL)
	{
		return (NULL);
	}
	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	if (str == NULL)
	{
		new->str = NULL;
	}
	else
	{
		new->str = strdup(str);
	}
	new->len = _strlen(str);
	new->next = NULL;
	curr->next = new;
	return (new);
}
