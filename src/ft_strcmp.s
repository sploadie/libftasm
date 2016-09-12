; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/12 15:23:11 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 16:26:47 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcmp

section .text

_ft_strcmp:
	cmp rdi, 0
	je error
	cmp rsi, 0
	je error
	mov r10, rdi
	xor rcx, rcx
	not rcx
	xor rax, rax
	cld				; clear direction flag
	repne scasb
	not rcx
	mov rdi, r10
	repe cmpsb
	mov al, byte[rdi-1]
	xor r10, r10
	mov r10b, byte[rsi-1]
	sub eax, r10d
	ret
error:
	xor rax, rax
	ret