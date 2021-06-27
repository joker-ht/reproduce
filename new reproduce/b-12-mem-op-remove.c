#include <pthread.h>
int x = 23;
void* set_x() {
    x = 100;
}

int test(int y) {
    pthread_t p1;
    pthread_create(&p1, NULL, set_x, NULL);
    while (x < y){      
        y = y + 1; 
        if (x == y)
            break;
    }       
    return 0;
}