#include "lists.h"


/**
 * delete_dnodeint_at_index - Delete a node from a dlistint
 * @head: Pointer to start of the list
 * @index: Index of node to delete
 *
 * Return: 1 on success and -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *to_del, *prev;

	if (head == NULL)
		return (-1);
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		to_del = *head;
		*head = to_del->next;
		prev = NULL;
	}
	else
	{
		prev = *head;
		while (index > 1)
		{
			prev = prev->next;
			if (prev == NULL)
				return (-1);
			index--;
		}
		to_del = prev->next;
		if (to_del == NULL)
			return (-1);
	}
	if (prev != NULL)
	{
		prev->next = to_del->next;
	}
	if (to_del->next != NULL)
	{
		to_del->next->prev = prev;
	}
	free(to_del);
	return (1);
}
