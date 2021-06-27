/*successful
    x86-64 gcc 4.1-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
int test(int a) {
    if (a + 10 > a) {   // removed
        puts("ok");
    }
}

#include<stdio.h>
int main(){
    int a = 0x0fffffff;
    test(a);
    return 0;
}