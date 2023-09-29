#include <stdio.h>
#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 1 for little endian, 0 for big endian.
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *byte_ptr = (char *)&num;

    if (*byte_ptr == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
