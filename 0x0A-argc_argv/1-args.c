#include <stdio.h>
/**
 * main - print a number followed by a new line.
 * @argc: number of command line arg.
 * @argv: array of that conatains the program command line arg.
 * Return: 0 - success.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc -1);
	return (0);
}
