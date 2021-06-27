#include<stdio.h>

struct ccc {
    int a;
    int b;
};



__attribute__((noinline)) int change (int* c){
    *c = *(c + 1);
    return 300;
}

int main(){
    struct ccc case1
    = {100,500};

    case1.b = 10000000;
    case1.b = change((int*)&case1);
    printf("%d\n", case1.b);
    printf("%d", case1.a);
    return 0;
}