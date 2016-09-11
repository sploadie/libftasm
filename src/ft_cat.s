; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 18:17:59 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/11 18:58:46 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_cat

section .text

_ft_cat:
	push rbp			; stack prep
	mov rbp, rsp		;

	cmp edi, -1
	je end
	cmp edi, 255
	jg end

read_loop:
	push rdi			; read
	lea rsi, [rel buf]
	mov rdx, 256
	mov rax, 0x2000003
	syscall
	jc end_loop			; check for error
	cmp rax, 0			; check for end
	je end_loop

	mov rdi, 1			; write
	lea rsi, [rel buf]
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	jc end_loop			; check for error
	pop rdi
	jmp read_loop
end_loop:
	pop rdi
end:
	mov rsp, rbp		; stack cleanup
	pop rbp				;
	ret

section .data

buf: times 256 db 0
