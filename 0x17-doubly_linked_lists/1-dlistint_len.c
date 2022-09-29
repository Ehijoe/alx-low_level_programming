#include "lists.h"


/**
 * dlistint_len - Return the length of a doubly linked list
 * @h: Pointer to the first node
 *
 * Return: The length
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t *curr;
	size_t len = 0;

	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
