
#### l_1-mcp_null3.c

calling standard memcpy(src,dst,size) with src == NULL && size == 0 don't cause crash (confirm on CentOS Linux release 7.6.1810), and can cause later null-checks on src or zero-checks on size removed.

```c
/*glibc memcpy, when len == 0, only BYTE_COPY_FWD (dstp, srcp, len) is called*/
/* https://github.com/lattera/glibc/blob/master/string/memcpy.c */

void *
memcpy (void *dstpp, const void *srcpp, size_t len)
{
  unsigned long int dstp = (long int) dstpp;
  unsigned long int srcp = (long int) srcpp;

  /* Copy from the beginning to the end.  */

  /* If there not too few bytes to copy, use word copy.  */
  if (len >= OP_T_THRES)
    {
      /* Copy just a few bytes to make DSTP aligned.  */
      len -= (-dstp) % OPSIZ;
      BYTE_COPY_FWD (dstp, srcp, (-dstp) % OPSIZ);

      /* Copy whole pages from SRCP to DSTP by virtual address manipulation,
	 as much as possible.  */

      PAGE_COPY_FWD_MAYBE (dstp, srcp, len, len);

      /* Copy from SRCP to DSTP taking advantage of the known alignment of
	 DSTP.  Number of bytes remaining is put in the third argument,
	 i.e. in LEN.  This number may vary from machine to machine.  */

      WORD_COPY_FWD (dstp, srcp, len, len);

      /* Fall out and copy the tail.  */
    }

  /* There are just a few bytes to copy.  Use byte memory operations.  */
  BYTE_COPY_FWD (dstp, srcp, len);

  return dstpp;
}

/*glibc BYTE_COPY_FWD, it will do nothing with nbytes == 0*/
/*https://code.woboq.org/userspace/glibc/sysdeps/generic/memcopy.h.html*/

#define BYTE_COPY_FWD(dst_bp, src_bp, nbytes)                                      
  do                                                                         
    {                                                                              
      size_t __nbytes = (nbytes);                                              
      while (__nbytes > 0)                                                      
        {                                                                      
          byte __x = ((byte *) src_bp)[0];                                      
          src_bp += 1;                                                              
          __nbytes -= 1;                                                      
          ((byte *) dst_bp)[0] = __x;                                              
          dst_bp += 1;                                                              
        }                                                                      
    } while (0)

```
Based on above code, it seems that standard memcpy(src,dst,size) with size==0 will do nothing.
