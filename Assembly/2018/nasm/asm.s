section .data                                    ; initialized data
    msg: db "Hello, World!", 10, 0               ; message to be displayed

section .bss                                     ; uninitialized data
    ; empty

section .text                                    ; assembly code

external printf
global start
start:
    push    ebp
    mov     ebp, esp
    push    msg
    call    printf
    mov     esp, ebp
    ret
