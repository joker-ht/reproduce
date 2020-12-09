/*successful
    x86-64 gcc 4.1.2-10.1 -O1
    x86-64 clang 3.0.0-11.0.0 -O1
    arm gcc gcc 5.4-9.2.1 -O1
    arm clang 9.0.0-11.0.0 -O1
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

struct a {
    uint32_t t1;
    uint32_t t2;
};

int main () {
    struct a *b = (struct a*)malloc(sizeof(struct a));
    if (&(b->t2) != NULL)
        printf("hahahah\n");
    return 0;
}