#include "lists.h"


/**
 * sum_dlistint - Add all items in a dlistint
 * @head: The start of the list
 *
 * Return: The sum of items in the list
 */
int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);
	return (head->n + sum_dlistint(head->next));
}
