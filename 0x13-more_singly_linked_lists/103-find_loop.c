#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *limit;
	int c;
	int i;

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

	fast = slow->next;
	for (c = 1; fast != slow; c++)
		fast = fast->next;

	limit = slow->next;
	slow = head;
	fast = head;
	while (slow != limit)
	{
		for (i = 0; i < c; i++)
		{
			fast = fast->next;
		}
		if (slow == fast)
			return (slow);
		slow = slow->next;
		fast = slow;
	}
}
