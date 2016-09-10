; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 13:34:21 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/10 16:04:18 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcat

section	.text

_ft_strcat:
	cmp rdi, 0			; s1 not NULL
	je end
	cmp rsi, 0			; s2 not NULL
	je end
	mov r11, rdi		; save s1
	cld					; direction flag -> inc
	xor al, al			; scan value = '\0'

	; get s1(end)

	xor rcx, rcx		; clear iterator
	not rcx				; max iterator
	repne scasb			; scan s1 to '\0'
	dec rdi				; decrement (scan goes over one)
	mov r10, rdi		; save s1(end)

	; get s2(len)

	mov rdi, rsi
	xor rcx, rcx
	not rcx
	repne scasb
	not rcx				; iterator now equal to s2(len) + 1

	; copy s2 to s1

	mov rdi, r10
	rep movsb
	mov rax, r11
end:
	ret
