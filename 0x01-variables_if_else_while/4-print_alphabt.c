#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * main - Pirnts the alphabet without q and e
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
