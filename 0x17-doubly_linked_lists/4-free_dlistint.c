#include "lists.h"


/**
 * free_dlistint - Free the memory occupied by a dlistint
 * @head: The start of the list
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	free_dlistint(head->next);
	free(head);
}
