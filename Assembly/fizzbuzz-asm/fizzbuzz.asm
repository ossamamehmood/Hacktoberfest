	global _start
	extern write_number
	section .text
write:
	push rcx
	mov rax, 1
	mov rdi, 1
	syscall
	pop rcx
	ret
divide:
	mov rdx, 0
	div rdi
	ret
_start:
	mov rcx, 1
_loop:
	mov rsi, 0
	mov rax, rcx
	mov rdi, 3
	call divide
	cmp rdx, 0
	jne div_by_five
	add rsi, 1
div_by_five:
	mov rdi, 5
	mov rax, rcx
	call divide
	cmp rdx, 0
	jne print_decision
	add rsi, 2
print_decision:
	cmp rsi, 0
	je print_num
	cmp rsi, 1
	je print_fizz
	cmp rsi, 2
	je print_buzz
	jmp print_fizzbuzz	
print_fizzbuzz:
	mov rsi, fizzbuzz
	mov rdx, 9
	call write
	jmp endif
print_fizz:
	mov rsi, fizz 
	mov rdx, 5
	call write
	jmp endif
print_buzz:
	mov rsi, buzz,
	mov rdx, 5
	call write
	jmp endif
print_num:
	push rcx
	mov rdx, 0
	mov rax, rcx
	call write_number
	pop rcx
	mov rsi, newline
	mov rdx, 1
	call write
	jmp endif
endif:
	inc rcx
	cmp rcx, 100
	jle _loop
	mov rax, 60
	xor rdi, rdi
	syscall

	section .data
fizz: db "fizz", 10
buzz: db "buzz", 10
fizzbuzz: db "fizzbuzz", 10
newline: db 10
