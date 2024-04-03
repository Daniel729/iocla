%include "printf32.asm"

section .text
    global main
    extern printf

main:
    mov eax, 7       ; vrem sa aflam al N-lea numar; N = 7
    mov ecx, eax
    xor eax, eax
    mov ebx, 1
calc_loop:
    lea edx, [eax + ebx]
    mov eax, ebx
    mov ebx, edx     
    loop calc_loop

    ; TODO: calculati al N-lea numar fibonacci (f(0) = 0, f(1) = 1)
    PRINTF32 `%d\n\x0`, eax ;
    ret
