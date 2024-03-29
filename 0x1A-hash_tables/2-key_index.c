#include "hash_tables.h"

/**
 * key_index - returns the i of a key
 * @key: key
 * @size: size of hash table
 *
 * Return: the i of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0)
		return (0);

	return (hash_djb2(key) % size);
}
