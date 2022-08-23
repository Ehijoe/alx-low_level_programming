#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_ERR(filename) \
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", (filename))

#define WRITE_ERR(filename)						\
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", (filename))

/**
 * close_files - Close the files used by cp
 * @fd1: First file descriptor
 * @fd2: Second file descriptor
 */
void close_files(int fd1, int fd2)
{
	int stat1, stat2;

	stat1 = close(fd1);
	stat2 = close(fd2);
	if (stat1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
	}
	if (stat2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
	}
	if (stat1 == -1 || stat2 == -1)
		exit(100);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: List of arguments
 *
 * Return: 0 on Success.
 *         97 if incorrect number of arguments is passed
 *         98 if there is an error opening or reading input file
 *         99 if there is an error opening or writing output file
 *         100 if there is an error closing a file
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	ssize_t len = 1024;
	int in_fd, out_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
	{
		READ_ERR(argv[1]);
		exit(98);
	}
	out_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 00664);
	if (out_fd == -1)
	{
		WRITE_ERR(argv[2]);
		exit(99);
	}
	while (len == 1024)
	{
		len = read(in_fd, buffer, 1024);
		if (len == -1)
		{
			READ_ERR(argv[1]);
			exit(98);
		}
		if (write(out_fd, buffer, len) != len)
		{
			WRITE_ERR(argv[2]);
			exit(99);
		}
	}
	close_files(in_fd, out_fd);
	return (0);
}
