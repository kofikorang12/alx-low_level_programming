#include "main.h"
/**
 * _sqrt_recursion - return the natural square root of a number.
 * @n: input number.
 * @c: iterator.
 * Return: square root or -1.
 *
 * power_operation - returns the natural square root of a number.
 * @n: input number.
 * Return: natural Square root.
 */
int power_operation(int n, int c)
{
	if (c % (n / c) == 0)
	{
		if (c * (n / c) == n)
		       return (c);
		else
		return (-1);	
	}
	return (0 + power_operation(n, c + 1));
}
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (number(1, n));
}
