// commit https://github.com/torvalds/linux/commit/d50f2ab6f050311dbf7b8f5501b25f0bf64a439b
#include <stdio.h>

__attribute__((noinline))  int test(int a){
    int b = 1 << a;
    if (b == 0)                 // x86-64 clang3.0-trunk -O
        return 1;
    return 0;
}

int main(){
    int a = 31;
    printf("%d", test(a));
    return 0;
}


/*
asm code:
test:                                   # @test
        xor     EAX, EAX
        ret

main:                                   # @main
        push    RBP
        mov     RBP, RSP
        mov     EDI, .L.str
        xor     ESI, ESI
        xor     AL, AL
        call    printf
        xor     EAX, EAX
        pop     RBP
        ret

.L.str:
        .asciz   "%d"
*/