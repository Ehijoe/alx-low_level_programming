#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Print a linked list of integers
 * @h: A pointer to the first node of the list
 *
 * Return: The number of elements in the list
 */
size_t print_listint(const listint_t *h)
{
	if (h == NULL)
	{
		return (0);
	}
	printf("%d\n", h->n);
	return (1 + print_listint(h->next));
}
