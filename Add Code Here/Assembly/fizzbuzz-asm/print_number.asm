global write_number
section .text
write_number:
    mov rcx, 0
    mov rdi, 10
_loop:
    inc rcx
    div rdi
    push rdx
    mov rdx, 0
    cmp rax, 0
    jne _loop
_print:
    pop rax
    add rax, '0'
    mov [num], ax
    mov rax, 1
    mov rdi, 1
    mov rsi, num
    mov rdx, 1
    push rcx
    syscall
    pop rcx
    loop _print
    ret

section .bss
num: resb 1
