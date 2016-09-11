; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/11 12:55:07 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isascii

section .text

_ft_isascii:
	cmp edi, 0		; false if less than 0
	jl false
	cmp edi, 127	; false if greater than 127
	jg false
	mov eax, 1
	ret
false:
	mov eax, 0
	ret
