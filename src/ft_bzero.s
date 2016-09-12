; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 12:59:56 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 15:28:55 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_bzero

section .text

_ft_bzero:			; void bzero(void *s, size_t n);
	cmp rdi, 0		; ret if s == NULL
	je end
	xor al, al
	mov rcx, rsi
	cld				; clear direction flag
	rep stosb
end:
	ret
