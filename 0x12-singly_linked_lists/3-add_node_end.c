#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *word, *temp;
	size_t nchar;

	word = malloc(sizeof(list_t));
	if (word == NULL)
		return (NULL);

	word->str = strdup(str);

	for (nchar = 0; str[nchar]; nchar++)
		;

	word->len = nchar;
	word->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = word;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = word;
	}

	return (*head);
}
