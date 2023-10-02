#include <stdio.h>
#include <stdlib.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters) {
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

    ssize_t bytesRead = fread(buffer, 1, letters, file);
    if (bytesRead <= 0) {
        fclose(file);
        free(buffer);
        return 0;
    }

    buffer[bytesRead] = '\0';

    ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
    if (bytesWritten != bytesRead) {
        fclose(file);
        free(buffer);
        return 0;
    }

    fclose(file);
    free(buffer);
    
    return bytesWritten;
}
