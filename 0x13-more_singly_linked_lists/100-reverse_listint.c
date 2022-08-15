#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: A pointer to the linked list to reverse
 *
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *curr;
	listint_t *next;

	if (head == NULL)
		return (NULL);
	if (*head == NULL)
		return (NULL);
	curr = *head;
	next = curr->next;
	curr->next = NULL;
	while (next != NULL)
	{
		*head = curr;
		curr = next;
		next = next->next;
		curr->next = *head;
	}
	*head = curr;
	return (curr);
}
