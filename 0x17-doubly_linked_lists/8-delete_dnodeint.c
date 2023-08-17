#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a given index
 * @head: linked list
 * @index: index of node to be deleted
 *
 * Return: 1 if success, -1 if failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *ptrt;
	dlistint_t *Nex;
	dlistint_t *Prev;

	if (head == NULL || *head == NULL)
		return (-1);

	ptrt = *head;

	if (index == 0)
	{
		Nex = ptrt->nex;
		if (Nex != NULL)
			Nex->prev = NULL;
		free(ptrt);
		*head = Nex;
		return (1);
	}

	for (i = 0; i < index && ptrt->nex != NULL; i++)
		ptrt = ptrt->nex;

	if (i < index)
		return (-1);

	Nex = ptrt->nex;
	Prev = ptrt->prev;

	if (Nex != NULL)
		Nex->prev = Prev;

	Prev->nex = Nex;
	free(ptrt);

	return (1);
}
