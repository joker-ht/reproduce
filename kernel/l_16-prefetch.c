/*successful
    x86-64 gcc 4.1.2 -O2
    x86-64 clang 3.0.0 -O2
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define prefetch(ptr)				\
	({					\
		__asm__ __volatile__(		\
		"pld\t%0"			\
		:				\
		: "o" (*(char *)(ptr))		\
		: "cc");			\
	})

int main() {
    char* a;
    prefetch(a);
    if (a)
        printf("hahahah\n");
    return 0;
}