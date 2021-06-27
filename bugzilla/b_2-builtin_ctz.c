/*successful
    x86-64 gcc 4.8-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
#include<stdio.h>

void test(int p){
    
    if(__builtin_ctz(p)>= 32) // removed
        printf("a");

}

int main(){
    int a = 0;
    test(a);

}