; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_pow.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/12 18:46:20 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 19:01:39 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_pow

section .text

_ft_pow:
	mov eax, 1		; return 1 if exponent is 0
	cmp esi, 0
	je end
	xor rcx, rcx	; set clean iterator (exponent)
	mov ecx, esi
	xor edx, edx	; empty upper mul result
lp_start:
	mul edi			; eax * edi -> edx:eax
	cmp edx, 0		; exit if overflow
	jne error
	loop lp_start
end:
	ret

error:
	xor rax, rax
	ret