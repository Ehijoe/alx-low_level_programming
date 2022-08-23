#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_value - Prints a Key-Value pair
 * @key: The key
 * @value: The value
 */
void print_value(char *key, char *value)
{
	printf("  %-35s%s\n", key, value);
}

/**
 * check_magic - Check the magic numbers of an elf headers
 * @header: A pointer to the header bytes
 */
void check_magic(char *header)
{
	int i;
	char magic[] = "aELF";

	magic[0] = '\x7f';
	for (i = 0; i < 4; i++)
	{
		if (header[i] != magic[i])
		{
			write(STDERR_FILENO, "Error: Not an ELF file.\n", 24);
			exit(98);
		}
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x", header[i]);
		if (i == 15)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an elf file
 * @header: A pointer to the header bytes
 */
void print_class(char *header)
{
	if (header[4] == 2)
	{
		print_value("Class:", "ELF64");
	}
	else if (header[4] == 1)
	{
		print_value("Class:", "ELF32");
	}
	else
	{
		print_value("Class:", "This class is invalid");
	}
}

/**
 * print_data - Prints the data representation of the file
 * @header: A pointer to the header bytes
 */
void print_data(char *header)
{
	char *data;

	if (header[5] == 2)
	{
		data = "big";
	}
	else if (header[5] == 1)
	{
		data = "little";
	}
	else
	{
		print_value("Data:", "Unknown data format");
	}
	printf("  %-35s2's complement, %s endian\n", "Data:", data);
}

/**
 * print_version - Prints the version of the program
 * @header: A pointer to the header bytes
 */
void print_version(char *header)
{
	if (header[6] == 1)
	{
		print_value("Version:", "1 (current)");
	}
	else
	{
		printf("  %-35s%d (invalid)\n", "Version:", header[6]);
	}
}

/**
 * print_OS - Prints the OS/ABI
 * @header: A pointer to the header bytes
 */
void print_OS(char *header)
{
	char *os;

	switch (header[7])
	{
	case 0:
		os = "UNIX - System V";
		break;
	case 2:
		os = "UNIX - NetBSD";
		break;
	case 3:
		os = "Linux";
		break;
	case 6:
		os = "UNIX - Solaris";
		break;
	default:
		printf("  %-35s\n", "OS/ABI:", header[7]);
		return;
	}
	print_value("OS/ABI:", os);
}

/**
 * print_type - Prints the type of executable
 * @header: A pointer to the header bytes
 */
void print_type(char *header)
{
	char *type;
	int endian = header[5] - 1;

	switch (header[16 + endian])
	{
	case ET_NONE:
		type = "Unknown";
		break;
	case ET_EXEC:
		type = "EXEC (Executable file)";
		break;
	case ET_DYN:
		type = "DYN (Shared object file)";
		break;
	default:
		type = "Unknown";
		break;
	}
	print_value("Type:", type);
}

/**
 * print_entry - Prints the entry point address
 * @header: A pointer to the header bytes.
 * @bytes: The length of the address in bytes.
 */
void print_entry(char *header, int bytes)
{
	int i;
	unsigned long int p;

	p = 0;
	if (header[5] == 2)
	{
		for (i = 0; i < bytes; i++)
		{
			p <<= 8;
			p += header[24 + i];
		}
	}
	else
	{
		for (i = bytes - 1; i >= 0; i--)
		{
			p <<= 8;
			p += header[24 + i];
		}
	}
	printf("  %-35s%p\n", "Entry point address:", (void *) p);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on Success. 98 on error.
 */
int main(int argc, char **argv)
{
	char header[32];
	int fd;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Could not open file.\n", 28);
		exit(98);
	}
	if (read(fd, header, 32) != 32)
	{
		close(fd);
		write(STDERR_FILENO, "Error: Could not read file.\n", 28);
		exit(98);
	}
	check_magic(header);
	print_class(header);
	print_data(header);
	print_version(header);
	print_OS(header);
	printf("  %-35s%d\n", "ABI Version", header[8]);
	print_type(header);
	if (header[4] == 2)
	{
		print_entry(header, 8);
	}
	else
	{
		print_entry(header, 4);
	}

	close(fd);
	return (0);
}
