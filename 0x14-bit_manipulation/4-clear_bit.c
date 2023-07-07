#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index in the binary
 * representation of a number
 * @n: number to be evaluated
 * @index: index of bit to be evaluated
 *
 * Return: 1 if successful, -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int count = 1;

	if (index > MAX_INDEX)
		return (-1);

	count = count << index;

	if ((count & *n) > 0)
		*n -= count;

	return (1);
}
