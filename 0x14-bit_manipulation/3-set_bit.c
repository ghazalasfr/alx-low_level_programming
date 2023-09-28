#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * set_bit - set the value of a bit at a given index
  * @n: The number to find the index
  * @index: The index to find
  *
  * Return: the value of the bit at index index or -1 
  */

int  set_bit(unsigned long int *n, unsigned int index){
   if (index > sizeof(unsigned long int) * 8)
		return (-1);

	return ((*n |= 1 << index) ? 1 : -1);
    
}
