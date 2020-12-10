#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    char* a = (char*)malloc(1000);
    char* b = NULL;
    unsigned int len = 0;
    scanf("%s",a);
    scanf("%u",&len);
    if (len)
         b = (char*)malloc(1000);
    memcpy(b,a,len);
    if (b == NULL && len == 0)
        printf("null pointer\n");
    else {
        *b = 'a';
        printf("%s\n",*b);
    }
    return 0;
}
