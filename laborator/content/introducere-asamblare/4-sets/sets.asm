%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 0b10001011 ; 139 in binary
    mov ebx, 0b10101001 ; 169 in binary
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

    ; TODO1: reuniunea a doua multimi
    mov ecx, eax
    or ecx, ebx
    PRINTF32 `%u\n\x0`, ecx ; reuniunea celor doua multimi

    ; TODO2: adaugarea unui element in multime
    or ecx, 0b01010000
    PRINTF32 `%u\n\x0`, ecx ; noua multime

    ; TODO3: intersectia a doua multimi
    mov ecx, eax
    xor ecx, ebx
    PRINTF32 `%u\n\x0`, ecx ; intersectia celor doua multimi

    ; TODO4: complementul unei multimi
    mov ecx, eax
    not ecx
    PRINTF32 `%u\n\x0`, ecx ; complementul lui eax

    ; TODO5: eliminarea unui element
    mov edx, 0b10000000
    andn ecx, edx, eax
    PRINTF32 `%u\n\x0`, ecx ; eax fara un element

    ; TODO6: diferenta de multimi EAX-EBX
    mov edx, eax
    xor edx, ebx
    mov ecx, eax
    sub ecx, edx
    PRINTF32 `%u\n\x0`, ecx ; eax fara abx

    xor eax, eax
    ret
