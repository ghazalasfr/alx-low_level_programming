#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  * read_textfile - ...
  * @filename: The source file
  * @letters: Number of letters to reads and prints
  *
  * Return: ...
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, readedlettres;
	char *buffer = malloc(sizeof(char *) * letters);

	if (buffer == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY, 0600);
	if (file == -1)
		return (0);

	readedletters = read(file, buffer, letters);
	write(STDOUT_FILENO, buffer, readedletters);

	free(buffer);
	close(file);
	return (readedletters);
}
