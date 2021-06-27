/*successful
    x86-64 gcc 5-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n;
    char *password;
    char *otherthing;

    // Get password
    puts("Input your password's size:");
    if (scanf("%d", &n) != 1) {
        exit(-1);
    }
    puts("Input your password:");
    password = malloc(n);
    if (read(0, password, n - 1) < 0) {
        exit(-1);
    }
    puts("Get it, please do not tell anyone else");

    // Play with password
    // ...
    // <Ignore ... for short>
    // ...

    // Clear password
    memset(password, '\x00', n); // Memset will be eliminated with option -O1/O2/O3
    free(password);

    // Info leak
    otherthing = malloc(n);
    for (int i = 0; i < n; i++) {
        printf("%c", otherthing[i]);
    }
    puts("");
}