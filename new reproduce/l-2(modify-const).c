#include<stdio.h>

const int b = 500;

int main(){

    *(int*) &b = 100;
    // int *p = &a;
    // *p = 100;
    printf("%d", b);
    return 0;
}

/*will always seg fault as b is a const global var, stored in .rodata section
except clang 9.0-trunk -O which remove "*(int*) &b = 100;" output 100
*/

#include<stdio.h>

const int b;

int main(){

    *(int*) &b = 100;
    // int *p = &a;
    // *p = 100;
    printf("%d", b);
    return 0;
}

/* 
    *(int*) &b = 100; removed on clang 11.0 O2
    clang 11.0 - trunk, O0 seg fault
    gcc 10.1 - trunk, O0/O2 seg fault
*/


#include<stdio.h>

int main(){

    const int a = 500;
    *(int*) &a = 100;
    // int *p = &a;
    // *p = 100;
    printf("%d", a);
    return 0;
}

/* will not seg fault
clang 500 -O0/1/2
gcc 100 -O0/1/2
*/

#include<stdio.h>

int main(){

    const int a;
    *(int*) &a = 100;
    // int *p = &a;
    // *p = 100;
    printf("%d", a);
    return 0;
}

/* all 100
*/

#include<stdio.h>

static const int b;

int main(){

    *(int*) &b = 100;
    // int *p = &a;
    // *p = 100;
    if (!b)
        printf("%d", b);
    return 0;
}