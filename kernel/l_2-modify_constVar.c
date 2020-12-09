#include<stdio.h>
int main(){
    const int a = 0;
    int *p = &a;
    *p = 1;
    if(a == 0)
        printf("0");
    return 0;
}