#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Adds text to the end of a file
 * @filename: The name of the file to append to
 * @text_content: A pointer to the text to append
 *
 * Return: 1 on success. -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t i = 0;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	while (text_content[i] != '\0')
	{
		if (write(fd, text_content + i, 1) != 1)
		{
			close(fd);
			return (-1);
		}
		i++;
	}

	close(fd);
	return (1);
}
