; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/10 13:56:37 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isprint

section .text

_ft_isprint:		; int _ft_isprint(int c);
	cmp edi, 32		; c < space
	jl false
	cmp edi, 126	; c > ~
	jg false
	mov eax, 1
	ret
false:
	mov eax, 0
	ret
