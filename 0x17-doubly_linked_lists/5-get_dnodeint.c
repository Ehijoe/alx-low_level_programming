#include "lists.h"


/**
 * get_dnodeint_at_index - Get the element at a particular index
 * @head: Start of the list
 * @index: Index to get element from
 *
 * Return: The Node at the index given
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	return get_dnodeint_at_index(head->next, index - 1);
}
