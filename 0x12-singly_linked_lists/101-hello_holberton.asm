section .data
    hello_message db 'Hello, Holberton', 10    ; The string to be printed followed by a newline

section .text
    extern printf                             ; Declare the external printf function

global main

main:
    ; Prepare arguments for printf
    mov rdi, hello_message                   ; RDI holds the format string
    xor rax, rax                             ; Clear RAX (printf is a variadic function, and RAX is used to indicate the number of vector registers used)
    
    ; Call printf
    call printf

    ; Return from main
    xor rax, rax                             ; Return 0
    ret
