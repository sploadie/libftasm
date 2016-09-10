; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/10 13:56:43 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isdigit

section .text

_ft_isdigit:		; int ft_isdigit(int c);
	cmp edi, '0'	; c < '0'
	jl false
	cmp edi, '9'	; c > '9'
	jg false
	mov eax, 1
	ret
false:
	mov eax, 0
	ret
