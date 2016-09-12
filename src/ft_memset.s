; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 16:08:02 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 15:29:25 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memset

section .text

_ft_memset:
	cmp rdi, 0
	je error
	mov r10, rdi
	mov al, sil
	mov rcx, rdx
	cld				; clear direction flag
	rep stosb

	mov rax, r10
	ret
error:
	mov rax, rdi
	ret
