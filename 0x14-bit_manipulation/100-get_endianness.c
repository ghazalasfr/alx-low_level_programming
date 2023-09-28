#include <stdio.h>
#include "main.h"

int get_endianness(void){
     unsigned int num = 1;
    char* byte_ptr = (char*)&num;

    if (*byte_ptr == 1) {
        return 1; 
    } else {
        return 0; 
    }
}
