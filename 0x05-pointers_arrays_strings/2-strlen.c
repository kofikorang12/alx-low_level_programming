#include "main.h"

/**
 * _strlen - returns the lenght of string.
 * @s: input string.
 * Return: lenght of a string.
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) 1= '\0')
		count++;
	return (count);
}
