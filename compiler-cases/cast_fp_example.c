#include <stdlib.h>
#include <stdio.h>
void A(int* s)
{
    printf("%d\n",*s);
}

void B(char* s)
{
    printf("%s\n",s);
}

int main() {
    void (*fp)(void*);
    int type;
    scanf("%d",&type);
    void* s;
    int a = 123;
    char* str = "hello world";
    if (type==1) {
        fp = (void (*)(void*)) &A;
        s = &a;
    }
    else {
        fp = (void (*)(void*)) &B;
        s = str;
    }
    fp(s);
    return 0;
}