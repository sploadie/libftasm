; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/12 16:57:41 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 17:16:43 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strchr

section .text

_ft_strchr:
	cmp rdi, 0
	je error
	mov r10, rdi
	xor rcx, rcx
	not rcx
	xor al, al
	repne scasb
	not rcx
	mov rdi, r10
	mov al, sil
	repne scasb
	cmp al, byte[rdi-1]
	jne error
	dec rdi
	mov rax, rdi
	ret
error:
	xor rax, rax
	ret