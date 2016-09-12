; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 16:08:02 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 15:29:18 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memcpy

section .text

_ft_memcpy:
	cmp rdi, 0
	je error
	cmp rsi, 0
	je error
	mov r10, rdi
	mov rcx, rdx
	cld				; clear direction flag
	rep movsb

	mov rax, r10
	ret
error:
	mov rax, rdi
	ret
