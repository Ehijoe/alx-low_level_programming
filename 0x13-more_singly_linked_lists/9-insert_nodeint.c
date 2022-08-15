#include "lists.h"

/**
 * insert_nodeint_at_index - Insert a node at a specified index
 * @head: A pointer to the list
 * @idx: Index to insert at
 * @n: The number to insert into the list
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	int i;
	listint_t *before;
	listint_t *new;

	if (head == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	before = *head;
	for (i = 1; i < idx; i++)
	{
		if (before == NULL)
			return (NULL);
		before = before->next;
	}
	new->next = before->next;
	before->next = new;
	return (new);
}
