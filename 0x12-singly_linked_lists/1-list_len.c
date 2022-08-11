#include "lists.h"

/**
 * list_len - Finds the length of a singly linked list
 * @h: A pointer to the first node in the list
 *
 * Return: The length of the list
 */
size_t list_len(const list_t *h)
{
	if (h == NULL)
	{
		return (0);
	}
	return (1 + list_len(h->next));
}
