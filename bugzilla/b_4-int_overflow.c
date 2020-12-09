#include<stdio.h>
int main(){
    int a = 0x0fffffff;
    if (a + 100 > a)
        printf("a");
    return 0;
}