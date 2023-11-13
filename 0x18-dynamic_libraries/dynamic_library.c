#include "main.h"
#include <stdio.h>

int _putchar(char c) {
    return 0;
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c) {
    return (_islower(c) || _isupper(c));
}

int _abs(int n) {
    return (n < 0) ? -n : n;
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

char *_strcpy(char *dest, char *src) {
    char *start = dest;
    while ((*dest++ = *src++));
    return start;
}

int _atoi(char *s) {
    return 0;
}

char *_strcat(char *dest, char *src) {
    return NULL;
}

char *_strncat(char *dest, char *src, int n) {
    return NULL;
}

char *_strncpy(char *dest, char *src, int n) {
    return NULL;
}

int _strcmp(char *s1, char *s2) {
    return 0;
}

char *_memset(char *s, char b, unsigned int n) {
    return NULL;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    return NULL;
}

char *_strchr(char *s, char c) {
    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    return 0;
}

char *_strpbrk(char *s, char *accept) {
    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    return NULL;
}
