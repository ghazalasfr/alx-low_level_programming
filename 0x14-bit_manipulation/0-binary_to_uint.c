#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The positive number converted from a binary.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0;
	unsigned int temp = 0;
	unsigned int nb = 0;

	if (b == NULL)
		return (0);

	nb = strlen(b);

	while (nb--) {
		if (b[nb] != '0' && b[nb] != '1')
			return (0);
		if (b[nb] == '1')
			dec += 1 << temp;
	temp++;

	}

	return (dec);
}
