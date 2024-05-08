section .data
    before_format db "before %s", 13, 10, 0
    after_format db "after %s", 13, 10, 0
    mystring db "abcdefghij", 0

section .text

extern printf
global main

toupper:
    push ebp
    mov ebp, esp

    ; TODO
    mov esi, [ebp + 8]
    
start:
    cmp byte [esi], 'a'
    jb continue

    cmp byte [esi], 'z'
    ja continue
    
    add byte [esi], 'A' - 'a'

continue:
    inc esi
    cmp byte [esi], 0
    jnz start

    leave
    ret

main:
    push ebp
    mov ebp, esp

    push mystring
    push before_format
    call printf
    add esp, 8

    push mystring
    call toupper
    add esp, 4

    push mystring
    push after_format
    call printf
    add esp, 8

    leave
    ret
