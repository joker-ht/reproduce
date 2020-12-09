#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int main() {

    char* a = (char*)malloc(100);
    char* b = (char*)malloc(50);
    char c;

    scanf("%s",a);
    c = a[20];
    memcpy(b,a,50);
    printf("%s\n",b);
    printf("%c\n",c);
    return 0;
}