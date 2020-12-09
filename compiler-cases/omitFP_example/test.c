#include <stdio.h>

int value;
int secret;

void risk() {
    // check
    if (value == 0) {
        printf("you are a bad guy!\n");
        return;
    }
    // check
    secret = 6666;
}

void normal() {
    printf("hello world!\n");
}

int main() {
    value = 0;
    secret = 0;
    void (*func_ptr)();
    scanf("%p",&func_ptr);
    func_ptr();
    printf("secret is %d\n",secret);
    return 0;
}