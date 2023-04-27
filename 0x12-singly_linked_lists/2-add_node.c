#include "lists.h"
/**
 * add_node - adds a new node beginning of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of head.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *word;
	size_t nchar;

	word = malloc(sizeof(list_t));
	if (word == NULL)
		return (NULL);

	word->str = strdup(str);

	for (nchar = 0; str[nchar]; nchar++)
		;

	word->len = nchar;
	word->next = *head;
	*head = word;

	return (*head);
}