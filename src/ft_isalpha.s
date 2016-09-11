; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/11 12:43:34 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalpha

section .text

_ft_isalpha:
	cmp edi, 'z'	; false if greater than z
	jg false
	and edi, 95		; downcase letter (a & 95 -> A)
	cmp edi, 'A'	; false if less than A
	jl false
	cmp edi, 'Z'	; false if greater than Z
	jg false
					; true if in between A and Z
true:
	mov eax, 1
	ret
false:
	mov eax, 0
	ret
