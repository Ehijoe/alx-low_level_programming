#include "lists.h"


/**
 * add_dnodeint_end - Add a node to the end of a dlistint
 * @head: Pointer to the start of the list
 * @n: The value to add
 *
 * Return: Pointer to the new node or NULL on error
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last, *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	last = *head;
	if (last == NULL)
	{
		*head = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	new->prev = last;
	return (new);
}
