#include "main.h"

/**
 * _isupper - checks if parameter is an upprecase character.
 * @c: input character.
 * Return: 1 if is an uppercase character, 0 in the other case
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
