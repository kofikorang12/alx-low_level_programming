#include "lists.h"
/**
 * free_dlistint - frees a linked list
 * @head: a pointer to the linked list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		cursor = head;
		head = head->next;
		free(tmp);
	}
}
