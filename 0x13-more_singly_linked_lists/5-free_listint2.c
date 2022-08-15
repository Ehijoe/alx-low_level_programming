#include "lists.h"

/**
 * free_listint - Frees the memory occupied by a list
 * @head: A pointer to the first node in the list
 */
void free_listint(listint_t *head)
{
	if (head == NULL)
	{
		return;
	}
	free_listint(head->next);
	free(head);
}

/**
 * free_listint2 - Frees a list and sets the head to NULL
 * @head: A pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;
	free_listint(*head);
	*head = NULL;
}
