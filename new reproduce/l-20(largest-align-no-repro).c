#include <stdio.h>
#include <stdlib.h>
// #include <bits/stdc++.h>
// using namespace std;

struct a{
    long long num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int num7;
    int num8;
};

struct b{
    int a;
    struct a stru;
};

int main(){
    // int k = 100;
    struct b stb = {1, {2,3}};
    int c = 100;
    printf("%d\n", sizeof(stb));
    printf("%d %d %d", &stb.a, &stb.stru.num1, c);
	
    return 0;
}