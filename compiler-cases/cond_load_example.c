// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdint.h>

/* successful
    x86-64 gcc 4.7.3-5.1 -O2 --param=allow-store-data-races=1

*/
#include <unistd.h>    
#include <sys/mman.h>
#include <errno.h>


int g_1 = 1;

int g_2[1024] __attribute__((section ("safe_section"), aligned (4096)));

int c = 4;

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
    //perror (e, e, "mprotect error %i", e);
    }
foo ();
__builtin_printf("OK\n");
return 0;
}