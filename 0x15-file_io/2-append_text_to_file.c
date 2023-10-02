#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  * append_text_to_file - the main function
  * @filename: name of the file
  * @text_content: the content of the file
  *
  * Return: ...
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	int len = 0;
	while (text_content[len])
		len++;

	if (text_content)
	{
		if (write(fd, text_content, len) == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
