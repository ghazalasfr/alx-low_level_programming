#include <stdio.h>
#include "main.h"
#include <string.h>

/*
 * binary_to_uint : for convert to int 
 *
 * @b : the nb to convert
 * return : the nb converted
 */

unsigned int binary_to_uint(const char *n){
    unsigned int dec =0, temp=0,nb=0;
    if(n==NULL) 
    return (0);
    nb=strlen(n);
   while (nb--)
	{
		if (n[nb] != 48 && n[nb] != 49)
			return (0);

		if (n[nb] == 49)
			dec += 1 << temp;

		temp++;
	}

	return (dec);
}
