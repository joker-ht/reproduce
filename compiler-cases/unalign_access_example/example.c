// #include <stdint.h>

// int main() {
//     char str[50];
//     scanf("%s",str);
//     char str2[50];
//     memcpy(str2,str,50);
//     return 0;
// }

/*successful
    arm gcc 5.4-9.2.1 -O1
    arm clang 9.0.0-11.0.0 -O1
*/

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* a = (char*)malloc(50);
    scanf("%s",a);
    uint64_t b;
    memcpy(a,&b,sizeof(uint64_t));
    printf("%u\n",b);
    printf("%s\n",a);
    return 0;
}