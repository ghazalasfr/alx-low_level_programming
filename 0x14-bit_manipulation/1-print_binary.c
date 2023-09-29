#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to represent in binary.
 *
 * Return: Nothing.
 */

void print_binary(unsigned long int n)
{
	if (n < 1) return;

	print_binary( n >> 1);

	if (n & 1)
		_putchar('1');
	else
		_putchar('0');
	
}
