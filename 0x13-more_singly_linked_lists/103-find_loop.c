#include "lists.h"

/**
 * find_listint_loop - Find the first node in a linked list to form a cycle
 * @head: A pointer to the first node of the linked list
 *
 * Return: A pointer to the first node of the cycle or NULL if there is none
 */
listint_t *find_listint_loop(listint_t *head)
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
		return (find_listint_loop(head->next));
	}
}
