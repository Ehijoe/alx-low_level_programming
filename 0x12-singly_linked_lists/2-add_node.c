#include "lists.h"
#include <string.h>

/**
 * add_node - Adds a node to the start of the list
 * @head: A pointer to the list(The list is a pointer to the first node)
 * @str: The string to store in the node
 *
 * Return: The address of the new node or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	new->next = *head;
	*head = new;
	return (new);
}
