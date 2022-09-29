#include "lists.h"


/**
 * insert_dnodeint_at_index - Insert a node at an index
 * @h: Pointer to the start of the list
 * @idx: Index to insert at
 * @n: The value to insert
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *prev, *new, **rest_of_list;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	prev = *h;
	while (idx > 1)
	{
		if (prev->next == NULL)
			return (NULL);
		prev = prev->next;
		idx--;
	}
	*rest_of_list = prev->next;
	new = add_dnodeint(rest_of_list, n);
	prev->next = new;
	new->prev = prev;
	return (new);
}
