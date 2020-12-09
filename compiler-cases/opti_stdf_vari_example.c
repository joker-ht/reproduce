#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
void memcpy_io(void* to,void* from,size_t count) {
    memcpy((void*)to,(void*)from,count);
}

int main() {
    //char* a = (char*)malloc(100);
    //char* b = (char*)malloc(100);
    uint32_t a;
    uint64_t b = 13213213;
    size_t count;
    scanf("%u",&a);
    memcpy_io(&b,&a,4);
    //memcpy(&b,&a,8);
    //scanf("%s",a);
    //memcpy_io((&b+10),&a,100);
    scanf("%u",&count);
    //memset(b,5,count);
    //printf("%s\n",a);
    printf("%s\n",b);
    return 0;
}