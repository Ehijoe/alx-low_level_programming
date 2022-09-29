#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;

	head = NULL;
	add_dnodeint(&head, 4);
	add_dnodeint(&head, 3);
	add_dnodeint(&head, 1);
	add_dnodeint(&head, 0);
	add_dnodeint_end(&head, 5);
	insert_dnodeint_at_index(&head, 7, 2);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 2);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 0);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 0);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 7);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 0);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 0);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 10);
	print_dlistint(head);
	printf("-------------------------\n");
	delete_dnodeint_at_index(&head, 0);
	print_dlistint(head);
	printf("-> %lu elements\n", dlistint_len(head));
	free_dlistint(head);
	return (EXIT_SUCCESS);
}
