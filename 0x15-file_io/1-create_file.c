#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes to it
 * @filename: Name of the file to create
 * @text_content: The text to write to the file
 *
 * Return: 1 on success. -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00600);
	if (fd == -1)
		return (-1);

	i = 0;
	while (text_content[i] != '\0')
	{
		if (write(fd, (text_content + i), 1) != 1)
		{
			close(fd);
			return (-1);
		}
		i++;
	}

	close(fd);
	return (1);
}
