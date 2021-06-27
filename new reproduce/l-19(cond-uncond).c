int g_1 = 1;

  int g_2[1024] __attribute__((section ("safe_section"), aligned (4096)));

  int c = 4;

#define PROT_READ 1
#define errno 1

  int __attribute__ ((noinline))
  foo (void)
  {
    int l;
    for (l = 0; (l != 4); l++) {
      if (g_1)
        return l;
      for (g_2[0] = 0; (g_2[0] >= 26); ++g_2[0])
        ;
    }
    return 2;
  }

  int main (int argc, char* argv[])
  {
    if (mprotect (g_2, sizeof(g_2), PROT_READ) == -1)
      {
        int e = errno;
        error (e, e, "mprotect error %i", e);
      }
    foo ();
    __builtin_printf("OK\n");
    return 0;
  }

// abstract case:


#include<stdio.h>

int x = 1, y = 2, z;

int test(){
    int i;
    for (i = 0; i < 4; i++) {
        if (x == 1)
            return 0;
        for (y = 100; y >= 26; --y)
        ;
    }

    // while(y < x) {
    //     if (z == 0)
    //         return 0;
    //     y++;
    // }

    return 2;

    
}

/* note: it's an optimization related with loop. The opti res will mainly affect concurrency code.
it's a speculation load with loop: store a var in reg at the beginning of a loop
to avoid multiple mem access
*/
/*
asm code
test:
        mov     eax, DWORD PTR x[rip]
        mov     ecx, DWORD PTR y[rip]   // y is loaded in ecx before the check(load and check has no dependency)
        mov     edx, 4
.L4:
        test    eax, eax
        je      .L7
        sub     edx, 1
        mov     ecx, 25
        jne     .L4
        mov     DWORD PTR y[rip], 25
        mov     eax, 2
        ret
.L7:
        mov     DWORD PTR y[rip], ecx    // intro new data race(there should be no store in this branch)
        ret
y:
        .long   2
x:
        .long   1
*/


// an other case(mem load -> reg load)
int test(){
    while(y < x) {
        if (z == 0)
            return 0;
        y++;
    }

    return 2;
}
/*
asm code:
        mov     eax, DWORD PTR y[rip]
        mov     edx, DWORD PTR x[rip]
        cmp     eax, edx
        jge     .L7
        mov     ecx, DWORD PTR z[rip]
        test    ecx, ecx
        je      .L8
.L6:
        add     eax, 1                          
        cmp     eax, edx
        jne     .L6
        mov     DWORD PTR y[rip], eax           // compiler store y after the loop, instead of doing it each circle
.L7:
        mov     eax, 2
        ret
.L8:
        xor     eax, eax
        ret
*/
