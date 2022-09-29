#include <stdio.h>

#include "lists.h"


/**
 * print_dlistint - Print all the elements of a doubly linked list
 * @h: Pointer to the first node
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;
	dlistint_t *curr;

	curr = h;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		len++;
	}
	return (len);
}
