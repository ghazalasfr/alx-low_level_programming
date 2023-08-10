#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * malloc_checked - Allocates memory
  * @s: the size to allocate
  *
  * Return: Nothing.
  */
void *malloc_checked(unsigned int s)
{
	void *k;

	k = malloc(s);

	if (k == NULL)
		exit(98);

	return (k);
}
