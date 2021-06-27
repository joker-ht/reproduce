if (!have_cpuid_p())
      identify_cpu_without_cpuid(c);

/* cyrix could have cpuid enabled via c_identify()*/
if (!have_cpuid_p())
    return;


// constructed case:
#include <stdio.h>
#include <stdlib.h>

int x;


void m(){
      x++;
}

// void (* testptr)() = m;


struct  c{
      int c1;
      void (* testptr)();
};



struct c k = {0, m};

// __attribute__((noinline))int foo1(int a){
//     return a ;

// }

__attribute__((noinline))int foo1(int flag){
    // return a ;
    unsigned int f1, f2;
	asm  ("pushfl\n\t"                  // this asm code load flag reg
		      "pushfl\n\t"
		      "popl %0\n\t"
		      "movl %0,%1\n\t"
		      "xorl %2,%0\n\t"
		      "pushl %0\n\t"
		      "popfl\n\t"
		      "pushfl\n\t"
		      "popl %0\n\t"
		      "popfl\n\t"
		      : "=&r" (f1), "=&r" (f2)
		      : "ir" (flag)
              );
              

	return ((f1^f2) & flag) != 0;

}

__attribute__((noinline))void foo2(){
    x++;
    // k.testptr();
}

int main(){
    int lm = 1, ln = 2;
    if (foo1(lm))
        foo2();
    if (foo1(lm))
        puts("aaa");

    printf("%d", x);
    return 0;
}

// compiler thinks foo1 non-global related, but foo1 can read global info(flag reg)