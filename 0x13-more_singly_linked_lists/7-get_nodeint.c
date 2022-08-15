#include "lists.h"

/**
 * get_nodeint_at_index - Gets the node at a particular index of a list
 * @head: A pointer to the first node in the list
 * @index: The index of the required element
 *
 * Return: A pointer to the node at index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (head == NULL)
	{
		return (NULL);
	}
	if (index == 0)
	{
		return (head);
	}
	return (get_nodeint_at_index(head->next, (index - 1)));
}
