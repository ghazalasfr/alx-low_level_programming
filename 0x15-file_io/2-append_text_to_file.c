#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
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
	int file;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	
	int c = 0;
	while (text_content[c])
		c++;

	if (text_content)
	{
		if (write(file, text_content, c) == -1)
			return (-1);
	}

	close(file);
	return (1);
}
