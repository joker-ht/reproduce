/*successful
    x86-64 gcc 4.1.2-10.1 -O0
    x86-64 clang 3.0.0-11.0.0 -O1
    arm gcc 4.5.4-9.2.1 -O0
    arm clang 9.0.0-11.0.0 -O1
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

static inline int32_t sign_extend32(uint32_t value,int index) {
    uint8_t shift = 31 - index;
    return  (int32_t)(value << shift) >> shift;
}

int main() {
    uint32_t a;
    int index;
    scanf("%u %d",&a,&index);
    int32_t b;
    b = sign_extend32(a,index);
    printf("%d\n",b);
    return 0;
}