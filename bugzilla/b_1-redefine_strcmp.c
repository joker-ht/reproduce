#include<stdio.h>

int strcmp (const char *s1, const char *s2)
{

    if ((!s1 && s2) || (s1 && !s2))
        return (int) (s1 - s2);

    if (s1 == s2)
        return 0;

    while (*s1 == *s2++)
        if (*s1++ == '\0')
             return 0;

    return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

int main(){
    char *p = NULL;
    char *q = "aaa";
    int a  = strcmp(p,q);
    printf("%d",a);
}