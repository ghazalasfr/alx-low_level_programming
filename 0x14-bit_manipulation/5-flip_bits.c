#include <stdlib.h>
#include "main.h"

/**
  * flip_bits - the main function that return int 
  * @n: first arg
  * @m: the second arg
  *
  * Return: number of bit to flip
  */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int temp = 0, count = 0;

	temp = n ^ m;
	while (temp)
	{
		if (temp & 1)
			count++;

		temp >>= 1;
	}

	return (count);
}
