; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 16:08:02 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 15:30:29 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

section .text

_ft_strlen:
	cmp rdi, 0
	je error
	xor rcx, rcx
	not rcx
	xor al, al
	cld				; clear direction flag
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret
error:
	mov rax, 0
	ret
