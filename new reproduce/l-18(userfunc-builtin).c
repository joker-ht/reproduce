//  https://github.com/torvalds/linux/commit/1bd46782d08b01b73df0085b51ea1021b19b44fd#
//  https://stackoverflow.com/questions/64648300/how-to-prevent-gcc-from-inserting-memset-during-link-time-optimization

struct bar {
    int a[100];
};

struct bar y;

void foo(){
  struct bar x = {{0}};
  y = x;            // with -fno-builtin, this still changed to memset
                    // x86 clang(all version) gcc(4.1.2) -O0 -fno-builtin -ffreestanding
                    // arm clang(all version) gcc(all version) -O0 -fno-builtin -ffreestanding
}

/* with memset
arm:
        push    {r4, r5, r11, lr}
        add     r11, sp, #8
        sub     sp, sp, #416
        add     r0, sp, #16
        mov     r1, #0
        mov     r2, #400
        str     r0, [sp, #12]           @ 4-byte Spill
        str     r2, [sp, #8]            @ 4-byte Spill
        bl      memset
        ldr     r1, .LCPI0_0
        str     r0, [sp, #4]            @ 4-byte Spill
        mov     r0, r1
        ldr     r1, [sp, #12]           @ 4-byte Reload
        ldr     r2, [sp, #8]            @ 4-byte Reload
        bl      memcpy
        sub     sp, r11, #8
        pop     {r4, r5, r11, lr}
        bx      lr

x86:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 400
        lea     rdi, [rbp - 400]
        xor     esi, esi
        mov     edx, 400
        call    memset@PLT
        lea     rsi, [rbp - 400]
        movabs  rdi, offset y
        mov     edx, 400
        call    memcpy@PLT
        add     rsp, 400
        pop     rbp
        ret


*/