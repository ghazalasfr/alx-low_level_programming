#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * print_binary - Prints the binary representation of a number
  * @n: The number to representing in binary
  *
  * Return: Nothing
  */

void print_binary(unsigned long int n)
{
    if (n==0 ) printf("0");
    while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
   }

}
