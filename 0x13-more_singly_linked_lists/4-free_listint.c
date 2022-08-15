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
