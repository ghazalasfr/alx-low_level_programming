#include "main.h"

/**
  * print_last_digit - Function to print the last digit of any nbre you give
  * @a: Digit to be computed
  *
  * Return: The last digit of type int
  */

int print_last_digit(int n)
{
	int b = n % 10;

	if (b < 0)
		b *= -1;

	_putchar(b + '0');

	return (b);
}
