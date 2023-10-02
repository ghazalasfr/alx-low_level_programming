#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  * append_text_to_file - ...
  * @filename: ...
  * @text_content: ...
  *
  * Return: ...
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fille, c = 0;

	if (filename == NULL)
		return (-1);

	fille = open(filename, O_WRONLY | O_APPEND);
	if (fille == -1)
		return (-1);

	
	while (text_content[c])
		c++;

	if (text_content) {
		if (write(fille, text_content, c) == -1)
			return (-1);
	}

	close(fille);
	return (1);
}
