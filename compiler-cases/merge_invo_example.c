#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

uint64_t array_idx_nospec(uint64_t index,uint64_t size) {
    uint64_t mask;
     asm ("cmp %1,%2; sbb %0,%0;"
	 		:"=r" (mask)
	 		:"g"(size),"r" (index)
 		:"cc");
    
    return mask;
}

int main() {
    char* array = (char*)malloc(2000);
    uint64_t idx = 500;
    scanf("%lu",&idx);
    uint64_t idx1;
    uint64_t idx2;


    if (idx < 2000) {
        idx1 = array_idx_nospec(idx,2000);
        printf("%c\n",array[idx1]);
    }

    if (idx < 2000) {
        idx2 = array_idx_nospec(idx,2000);
        printf("%c\n",array[idx2]+50);
    }
    
    return 0;
}