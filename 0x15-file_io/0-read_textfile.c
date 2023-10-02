#include <sdtio.h>
#include "main.h"
#include <stdlib.h>

/**
  * read_textfile - ...
  * @filename: The source file
  * @letters: Number of letters to reads and prints
  *
  * Return: number of lettre
  */

ssize_t read_textfile(const char *filename, size_t letters) 
{
	FILE *file;
	size_t readlettres;
	file= open(filename,"r");
	char *buffer = malloc(sizeof(char *) * letters);

	if (filename == NULL)
		return (0);
	if (file) 
		return (0);

	readed = read(file, buffer, letters);
	write(STDOUT_FILENO, buffer, readlettres);

	free(buffer);
	close(file);
	return (readlettres);
}
