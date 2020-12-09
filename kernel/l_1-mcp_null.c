#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
    x86-64 gcc 5.1-10.1 -O2
    x86-64 clang 3.0.0 -O2
    arm gcc 5.4-9.2.1 -O2

*/

int main() {
    char* a = (char*)malloc(1000);
    char* b = NULL;
    unsigned int len = 0;
    scanf("%s",a);
    scanf("%u",&len);
    if (len)
        b = (char*)malloc(1000);
    memcpy(b,a,len);
    if (b)
        printf("%s\n",b);
    return 0;
}