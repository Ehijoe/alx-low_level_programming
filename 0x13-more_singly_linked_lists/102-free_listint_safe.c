#include "lists.h"
#include <stdio.h>

/**
 * my_find_listint_loop - Find the last node in a linked list that has a cycle
 * @head: A pointer to the first node of the linked list
 *
 * Return: A pointer to the last node or NULL if there is no cycle
 */
listint_t *my_find_listint_loop(listint_t *head)
{
	listint_t *slow;
	listint_t *fast;

	slow = head;
	if (slow == NULL)
		return (NULL);
	fast = slow->next;
	if (fast == NULL)
		return (NULL);
	while (slow != fast)
	{
		if (slow == NULL || fast == NULL)
			return (NULL);
		if (fast->next == NULL)
			return (NULL);
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow->next == head)
	{
		return (slow);
	}
	else
	{
		return (my_find_listint_loop(head->next));
	}
}

/**
 * free_list_section - Frees a section of a linked list
 * @start: The first node of the list
 * @end: What comes after the last node
 *
 * Return: The number of nodes freed
 */
size_t free_list_section(listint_t *start, listint_t *end)
{
	int freed;

	if (start == NULL)
		return (0);
	if (start->next == end)
	{
		free(start);
		return (1);
	}
	freed = (1 + free_list_section(start->next, end));
	free(start);
	return (freed);
}

/**
 * free_listint_safe - Frees a list which may have a loop
 * @h: A pointer to the linked list
 *
 * Return: The number of elements printed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *loop_start;
	listint_t first_node;
	size_t freed;

	if (h == NULL)
		return (0);
	if (*h == NULL)
		return (0);
	first_node = **h;
	loop_start = my_find_listint_loop(&first_node);

	freed = free_list_section(*h, loop_start);
	*h = NULL;

	return (freed);
}
