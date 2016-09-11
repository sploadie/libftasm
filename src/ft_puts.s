; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/11 14:34:14 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_puts

section .text

_ft_puts:
	mov rsi, rdi		; write(X, str, X)
	xor rcx, rcx
	not rcx
	xor al, al
	repne scasb
	not rcx
	dec rcx
	mov rdx, rcx		; write(X, str, len)
	mov rdi, 1			; write(fd, str, len)
	mov rax, 0x2000004	; write @ 4
	syscall				; call write
	cmp rax, 0
	jl error
	
	mov rdi, 1			; write(fd, X, X)
	lea rsi, [rel endl]	; write(fd, str, X)
	mov rdx, 1			; write(fd, str, len)
	mov rax, 0x2000004	; write @ 4
	syscall				; call write
	cmp rax, 0
	jl error

	mov eax, 1
	ret

error:
	mov eax, -1
	ret

section .rodata

	endl db 10