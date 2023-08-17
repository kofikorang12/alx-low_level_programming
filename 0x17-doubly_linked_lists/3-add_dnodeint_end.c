#include "lists.h"

/**
 * add_dnodeint_end - adds new node to the end of a linked list
 * @head: a point linked list
 * @n: value of node to be added
 *
 * Return: the new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *cursor;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	cursor = *head;

	while (cursor->next != NULL)
		cursor = cursor->next;

	cursor->next = new_node;
	new_node->prev = cursor;

	return (new_node);
}
