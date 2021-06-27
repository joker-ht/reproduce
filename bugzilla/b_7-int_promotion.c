/*successful
    x86-64 gcc 4.4-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
#include<stdio.h>

void test(unsigned char a){
    if(a + 1)                   // removed
        printf("a");
}

int main(){
    int i = 255;
    test(i);
}