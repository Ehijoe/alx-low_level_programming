#include "lists.h"

/**
 * free_list - Frees a singly linked list
 * @head: A pointer to the first element of the list
 */
void free_list(list_t *head)
{
	if (head = NULL)
	{
		return;
	}
	free_list(head->next);
	free(head->str);
	free(head);
}
