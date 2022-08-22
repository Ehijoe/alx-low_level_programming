#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Writes the content of a file to stdout
 * @filename: The name of the file to open
 * @letters: Number of letters to read from the file
 *
 * Return: The number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t len;
	ssize_t written;

	if (letters == 0)
		return (0);
	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		return (0);
	}

	len = read(fd, buffer, letters);
	if (len == -1 || len == 0)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	written = write(STDIN_FILENO, buffer, len);
	if (written != len)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);
	return (written);
}
