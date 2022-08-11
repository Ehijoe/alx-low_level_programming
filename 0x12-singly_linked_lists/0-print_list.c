#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints a singly linked list
 * @h: A pointer to the first element of the list
 *
 * Return: The number of nodes printed
 */
size_t print_list(const list_t *h)
{
	if (h == NULL)
	{
		return (0);
	}
	if (h->str == NULL)
	{
		printf("[0] (nil)\n");
	}
	else
	{
		printf("[%d] %s\n", h->len, h->str);
	}
	return (1 + print_list(h->next));
}
