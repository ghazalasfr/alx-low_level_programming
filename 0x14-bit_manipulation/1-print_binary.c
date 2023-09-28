#include <stdio.h>

void print_binary(unsigned long int n){
    if (n==0 ) printf("0");
    while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
}

}
