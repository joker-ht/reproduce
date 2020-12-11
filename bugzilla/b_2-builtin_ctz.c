#include<stdio.h>

void test(int p){
    
    if(__builtin_ctz(p)>= 32) 
        printf("a");

}

int main(){
    int a = 0;
    test(a);

}