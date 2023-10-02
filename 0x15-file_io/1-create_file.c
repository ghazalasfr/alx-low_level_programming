#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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
	 int fd, c= 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	while (text_content[c])
		c++;
               
	if (text_content)
		write(fd, text_content, C);

	close(fd);
	return (1);
}
