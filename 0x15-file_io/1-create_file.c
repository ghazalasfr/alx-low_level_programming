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
	 if (filename == NULL)
		 return -1;
	 int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	 if (fd == -1)
		 return -1;

	 if (text_content != NULL) {
		 int len = _strlen(text_content);
		 ssize_t bytes_written = write(fd, text_content, len);

		 if (bytes_written == -1) {
			 close(fd);
			 return -1;
		 }
	 }

	 close(fd);
	 return 1;
}
