#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

uint64_t global_p = 777;
uint64_t global_p2 = 888;

int main() {

    int type = 0;
    scanf("%d",&type);
    uint64_t* p = (uint64_t*)malloc(8);
    if (type == 0)
        *p = global_p;
    else
        *p = global_p2;
    scanf("%lu",&global_p);
    scanf("%lu",&global_p2);
    printf("%lu\n",*p);
    printf("%lu\n",global_p);
    printf("%lu\n",global_p2);
    return 0;
}
