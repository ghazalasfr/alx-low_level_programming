#include <stdio.h>
#include "main.h"
#include <string.h>

/**
  * binary_to_uint - Converts a binary number to an unsigned int
  * @b: The binary string to converts
  *
  * Return: The positive number converted from a binary
  */

unsigned int binary_to_uint(const char *b){
    unsigned int dec =0, temp=0,nb=0;
    if(b==NULL) 
    return (0);
    nb=strlen(b);
   while (nb--)
	{
		if (b[nb] != 48 && b[nb] != 49)
			return (0);

		if (b[nb] == 49)
			dec += 1 << temp;

		temp++;
	}

	return (dec);
}