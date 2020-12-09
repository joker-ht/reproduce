void func()
{
    unsigned int i;

    unsigned int *ptr = (unsigned int*)0xfffff000;

    for (i = 0; i < 1024; i++)
        *(ptr++) = 0;
}