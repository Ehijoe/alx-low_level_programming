#include "lists.h"

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
