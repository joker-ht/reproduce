/*successful

    x86-64 gcc 4.1.2-10.1 -O2
    

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

struct type {
    uint32_t a;
    uint32_t b;
};

int main() {
    struct type* t = (struct type*)malloc(sizeof(struct type));
    //scanf("%u",&(t->a));
    scanf("%u",&(t->b));
    uint32_t tmp;
    tmp = t->b;
    printf("%u\n",tmp);
    return 0;
}