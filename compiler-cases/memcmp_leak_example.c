#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

int main() {
    char* a = malloc(100000);
    char* b = malloc(100000);
    scanf("%s",a);
    scanf("%s",b);
    int begin,end;
    begin = time(NULL);
    printf("result:%d\n",memcmp(a,b,100000));
    end = time(NULL);
    printf("time=%d\n",end-begin);
    return 0;
}