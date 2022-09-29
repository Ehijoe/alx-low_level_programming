#include "lists.h"


/**
 * add_dnodeint - Add a node to the start of a dlistint
 * @head: Pointer to the start of the list
 * @n: Value to add
 *
 * Return: Pointer to the newly inserted node or NULL on error
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
