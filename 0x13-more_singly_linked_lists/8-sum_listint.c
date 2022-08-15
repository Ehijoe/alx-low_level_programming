#include "lists.h"

/**
 * sum_listint - Add all the elements of a linked list
 * @head: A pointer to the first node in the list
 *
 * Return: The sum of all the elements in the list
 */
int sum_listint(listint_t *head)
{
	if (head == NULL)
	{
		return (0);
	}
	return (head->n + sum_listint(head->next));
}
