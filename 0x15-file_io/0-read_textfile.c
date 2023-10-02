#include <sdtio.h>
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile : the main function 
 * @filename : the name of the file
 * lettres : nbre of lettres reading
 * return : nbre of lettres 
 * */

ssize_t read_textfile(const char *filename, size_t letters) 
{
	if (filename == NULL) {
        return 0;
	}

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char *buffer = (char *)malloc(letters + 1);
    if (buffer == NULL) {
        fclose(file);
        return 0;
    }

    ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);
    if (bytesRead < 0) {
        fclose(file);
        free(buffer);
        return 0;
    }

    
    buffer[bytesRead] = '\0';

    ssize_t bytesWritten = printf("%s", buffer);
    if (bytesWritten != bytesRead) {
        fclose(file);
        free(buffer);
        return 0;
    }

    fclose(file);
    free(buffer);

    return bytesRead;
}
