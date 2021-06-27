# include <stdio.h>

struct a {
    int b;
    int p;
};

int test(struct a *test,int *p){

    printf("%x %x %x\n", test, &test->p, p);
    if (&test->b){      //  x86-64 clang: 3.0 - 3.4 -O
                        //           gcc: 4.1.2     -O0
        puts("aaa");
    }

    if (&test->p){      //  x86-64 clang: 3.3 - trunk   -O
                        //           gcc: 4.1.2 -O0 9.1-trunk  -O
        puts("aaa");
    }

    if(p) {             
        puts("aaa");
    }

    if(p + 1) {         //  x86-64 clang: 3.3 - trunk   -O
                        //           gcc: 9.1-trunk     -O
        puts("aaa");    
    }
}