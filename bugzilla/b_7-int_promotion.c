#include<stdio.h>

void test(unsigned char a){
    if(a + 1)
        printf("a");
}

int main(){
    int i = 255;
    test(i);
}