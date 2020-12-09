/* successful
    x86-64 gcc 5.1-10.1 -O2
    x86-64 clang 9.0.0-11.0.0 -O2
    arm gcc 5.4-9.2.1 -O2
    arm clang 9.0.0-11.0.0 -O2
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

const uint32_t base = 777;

int main () {
    uint32_t* p;
    p = (uint32_t*)&base;
    *p = 888;
    printf("%u\n",base);
    return 0;
}