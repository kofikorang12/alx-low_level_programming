#include "lists.h"

/**
 * get_dnodeint_at_index - return the nth node of linked list
 * @head: a pointer to the linked list
 * @index: the given index
 *
 * Return: return NULL if failure
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	tmp = head;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
