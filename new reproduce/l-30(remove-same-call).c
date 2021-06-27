commit https://github.com/torvalds/linux/commit/1186e4e904839955e5d2be94f50e0a363cb5651b
#include<stdio.h>
#include<pthread.h>
int x = 1;

__attribute__((noinline))int foo(int b){
    // barrier();       // with barrier, wont be removed
    return b + x;
}

void* set_x() {
    while(1)
        x += 1;
}

int main(){
    pthread_t p1;
    pthread_create(&p1, NULL, set_x, NULL);
    for(int i = 0; i < 10000000; i++)
    ;
    int k, m;
    k = foo(100);
    
    m = k + 1;
    k = foo(100);           //  removed in x86-64 all version of gcc and clang with -O in compiler explorer
    printf("%d %d", k, m);
}


// more likely case
#include<stdio.h>
#include<pthread.h>
int x = 1;

__attribute__((noinline))int foo(int b){
    // barrier();
    x += 1;
    return b + x;
}

void* set_x() {
    while(1)
        x += 1;
}

int main(){
    
    // for(int i = 0; i < 10000000; i++)
    // ;
    int k, m;
    k = foo(100);
    // foo(100);
    // m = foo(100);
    // x = 300;
    m = k + 1;
    k = foo(100);
    // foo(100);
    printf("%d %d", k, m);
}

/* noting removed in this case if 
input/output/call func/modify global var 
during 2 foo(100)
so can it happen like the kernel case?*/