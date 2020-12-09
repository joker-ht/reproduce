static char*  const kern_buff_p;

int hello_start(void)
{

 if(!kern_buff_p)
        printf("buffer is NULL for first time \n");

  *((char**)(unsigned long int)((&kern_buff_p)))=0xffff1100;

 if(!kern_buff_p)
        printf("buffer is NULL for second time \n");
}