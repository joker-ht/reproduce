int main(){
    int a;
    a = 10;
    int b = 1;
    asm volatile( 
        "movl    %a1, %%eax\n"
        "        movl    %%eax, %0"
            :"=r"(b)           /* output */
            :"r"(&a)              /* input */
            :        /* clobbered register */
        );
    printf("%d", b);
    return 0;
}

// cant reproduce