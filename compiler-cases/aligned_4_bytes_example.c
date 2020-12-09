#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

struct a {
    uint8_t t1;
    uint8_t t2;
};

int main() {
    struct a b;
    printf("size: %u",sizeof(b));
    return 0;
}