#include <stdio.h>
#include "main.h"
/**
  * get_bit - Gets the value of a bit at a given index
  * @n: The number to find the index
  * @index: The index to find
  *
  * Return: the value of the bit at index index or -1 
  */
int get_bit(unsigned long int n, unsigned int index){
    unsigned int compteur = 0;

	while (n)
	{
		if (compteur == index)
		{
			if (n % 2)
				return (1);
			else
				return (0);
		}

		n = n / 2;
		compteur++;
	}

	if (index > compteur && index < 63)
		return (0);

	return (-1);
    
}

