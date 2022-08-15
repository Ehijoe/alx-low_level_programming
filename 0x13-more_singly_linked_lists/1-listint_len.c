#include "lists.h"

/**
 * listint_len - Finds the lenght of a singly linked list
 * @h: A pointer to the first node in the list
 *
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	if (h == NULL)
	{
		return (0);
	}
	return (1 + listint_len(h->next));
}
