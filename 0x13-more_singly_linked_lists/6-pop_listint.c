#include "lists.h"

/**
 * pop_listint - Returns the first element in a
 * @head: A pointer to the list
 *
 * Return: The value of the first element in the list
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *new_head;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (0);
	n = (*head)->n;
	new_head = (*head)->next;
	free(*head);
	*head = new_head;
	return (n);
}
