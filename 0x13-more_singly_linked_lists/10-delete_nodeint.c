#include "lists.h"

/**
 * delete_nodeint_at_index - Delete the node of a list at a particular index
 * @head: A pointer to the list
 * @index: The index of the node to delete
 *
 * Return: 1 if successful and -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *to_del;
	listint_t *before;

	if (head == NULL)
		return (-1);
	to_del = *head;
	if (to_del == NULL)
		return (-1);
	before = NULL;
	for (i = 0; i < index; i++)
	{
		if (to_del == NULL)
			return (-1);
		before = to_del;
		to_del = to_del->next;
	}
	if (index == 0)
	{
		free(*head);
		*head = NULL;
		return (1);
	}
	before->next = to_del->next;
	free(to_del);
	return (1);
}
