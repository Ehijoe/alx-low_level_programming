#include "lists.h"

/**
 * add_nodeint - Adds a node to the start of a list
 * @head: A pointer to the list
 * @n: The number to add
 *
 * Return: A pointer to the newly added node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
