/*successful
    arm gcc 5.4 -O2
*/
void func()
{
    unsigned int i;

    unsigned int *ptr = (unsigned int*)0xfffff000;

    for (i = 0; i < 1024; i++)  // i < 1024 removed
        *(ptr++) = 0;
}