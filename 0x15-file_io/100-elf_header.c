#include "main.h"
#define BUFSIZE 32

/**
 * fill_struct - fill the elf struct with fields
 * @filename: the name of a given file
 * @h: the pointer to the header struct
 *
 * Return: 0 on success, -1 on fail
 */
int fill_struct(const char *filename, elf_hdr **h)
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
        (*h)->ei_magic[i] = buf[i];

    (*h)->ei_class = buf[4];
    (*h)->ei_data = buf[5];
    (*h)->ei_version = buf[6];
    (*h)->os_abi = buf[7];
    (*h)->abi_version = buf[8];
    (*h)->type = buf[16];

    for (i = 0; i < 4; i++)
        (*h)->entry_pt[i] = buf[24 + i];

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
    if (h->ei_magic[5] == 1)
        printf("2's complement, little endian\n");
    else
        printf("2's complement, big endian\n");
}

/**
 * print_version - prints the version of the elf header
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_version(const elf_hdr *h)
{
    printf("  Version:                           ");
    if (h->ei_version == 1)
        printf("%d (current)\n", h->ei_version);
    else
        printf("%s", "");
}

/**
 * print_os_abi - prints the os/abi of the elf file
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_os_abi(const elf_hdr *h)
{
    int i;
    os_abi osabi[] = {
        {0, "System V"},
        {1, "HP-UX"},
        {2, "NetBSD"},
        {3, "Linux"},
        {4, "GNU Hurd"},
        {6, "Solaris"},
        {7, "AIX"},
        {8, "IRIX"},
        {9, "FreeBSD"},
        {10, "Tru64"},
        {11, "Novell Modesto"},
        {12, "OpenBSD"},
        {13, "OpenVMS"},
        {14, "NonStop Kernel"},
        {15, "AROS"},
        {15, "Fenix OS"},
        {16, "CloudABI"},
        {17, "Stratus Technologies OpenVOS"}
    };

    printf("  OS/ABI:                            ");
    for (i = 0; i < 18; i++)
    {
        if (osabi[i].hex == h->os_abi)
        {
            printf("UNIX - %s\n", osabi[i].osabi_name);
            return;
        }
    }
    printf("<unknown: 53>");
}

/**
 * print_abi_version - prints the os/abi version of the elf file
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_abi_version(const elf_hdr *h)
{
    printf("  ABI Version:\t\t\t     ");
    printf("%d\n", h->abi_version);
}

/**
 * print_type - prints the type of the elf file
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_type(const elf_hdr *h)
{
    int i;

    elftype elftypes[] = {
        {0, "NONE", "Unknown file"},
        {1, "REL", "Relocatable file"},
        {2, "EXEC", "Executable file"},
        {3, "DYN", "Shared object file"},
        {4, "CORE", "Core file"}
    };

    printf("  Type:                              ");
    for (i = 0; i < 5; i++)
    {
        if (elftypes[i].hex == h->type)
        {
            printf("%s (%s)\n", elftypes[i].type, elftypes[i].object);
            return;
        }
    }
}

/**
 * print_entry_point - prints the entry point of the elf header
 * @h: the pointer to the header struct
 *
 * Return: void
 */
void print_entry_point(const elf_hdr *h)
{
    printf("  Entry point address:               0x");
    if (h->entry_pt[3] != 0)
        printf("%x", h->entry_pt[3]);
    if (h->entry_pt[2] != 0)
        printf("%x", h->entry_pt[2]);
    if (h->entry_pt[1] != 0)
        printf("%x", h->entry_pt[1]);
    if (h->entry_pt[0] != 0)
        printf("%x", h->entry_pt[0]);

    printf("\n");
}

/**
 * is_elf - checks if the file is ELF or not
 * @h: the pointer to the struct file
 *
 * Return: 1 if ELF, 0 otherwise
 */
int is_elf(const elf_hdr *h)
{
    if (h->ei_magic[1] == 'E' &&
        h->ei_magic[2] == 'L' &&
        h->ei_magic[3] == 'F')
        return 1;

    return 0;
}

/**
 * main - main function prints out the elf header
 * @ac: argument counter
 * @av: arguments vector
 *
 * Return: 0 always.
 */
int main(int ac, char **av)
{
    char *elf_file;
    elf_hdr *h;
    int n;

    if (ac != 2)
}