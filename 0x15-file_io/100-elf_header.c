#include "holberton.h"
#define BUFSIZE 32

/**
 * fill_struct - fill the elf struct with fields
 * @filename: the name of a given file
 * @h: the pointer to the header struct
 *
 * Return: 0 on success, -1 on failure
 */
int fill_struct(const char *filename, elf_hdr *h)
{
	int file_d;
	ssize_t file_r;
	char buf[BUFSIZE];
	int i;

	file_d = open(filename, O_RDWR);
	if (file_d < 0)
		return -1;

	file_r = read(file_d, buf, BUFSIZE);
	if (file_r < 0)
	{
		close(file_d);
		return -1;
	}

	for (i = 0; i < 16; i++)
		h->ei_magic[i] = buf[i];

	h->ei_class = buf[4];
	h->ei_data = buf[5];
	h->ei_version = buf[6];
	h->os_abi = buf[7];
	h->abi_version = buf[8];
	h->type = buf[16];

	for (i = 0; i < 4; i++)
		h->entry_pt[i] = buf[24 + i];

	close(file_d);
	return 0;
}

/**
 * print_magic - prints the magic number of the elf header
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_magic(const elf_hdr *h)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", h->ei_magic[i]);
	printf("\n");
}

/**
 * print_class - prints the class of the elf header
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_class(const elf_hdr *h)
{
	printf("  Class:                             ");
	if (h->ei_class == 1)
		printf("ELF32\n");
	else
		printf("ELF64\n");
}

/**
 * print_data - prints the data of the elf header
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_data(const elf_hdr *h)
{
	printf("  Data:                              ");
	if (h->ei_data == 1)
}