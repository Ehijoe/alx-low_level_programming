#include "lists.h"
#include <stdio.h>

/**
 * my_find_listint_loop - Find the first node in a linked list to form a cycle
 * @head: A pointer to the first node of the linked list
 *
 * Return: A pointer to the first node of the cycle or NULL if there is none
 */
listint_t *my_find_listint_loop2(listint_t *head)
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
		return (head);
	}
	else
	{
		return (my_find_listint_loop2(head->next));
	}
}

/**
 * print_listint_safe - Prints each element of a linked list exactly once
 * @head: A pointer to the first element of the linked list
 *
 * Return: The number of elements printed
 */
size_t print_listint_safe(const listint_t *head)
{
	int in_loop = 0;
	listint_t *loop_start;
	listint_t first_node;
	size_t len = 0;

	if (head == NULL)
		return (0);
	first_node = *head;
	loop_start = my_find_listint_loop2(&first_node);
	if (loop_start == NULL)
		in_loop = 1;

	while (head != loop_start || (!in_loop))
	{
		if (head == loop_start)
			in_loop = 1;
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		len++;
	}
	if (loop_start != NULL)
	{
		printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
		len++;
	}

	return (len);
}
