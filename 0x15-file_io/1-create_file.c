#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
  * create_file - ...
  * @filename: The source file
  * @text_content: letters to reads and prints
  *
  * Return: ...
  */
int create_file(const char *filename, char *text_content)
{
	 int file, len = 0;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	while (text_content[len])
		len = len + 1;

	if (text_content)
		write(file, text_content, len);

	close(file);
	return (1);
}
