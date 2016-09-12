; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 17:04:51 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 16:52:09 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memdup

extern _malloc

section .text

_ft_memdup:
	push rbp		; stack prep
	mov rbp, rsp	;

	cmp rdi, 0		; error if NULL
	je error
	push rdi		; save mem
	push rsi		; save mem length
	mov rdi, rsi	; call malloc with length
	call _malloc
	cmp rax, 0		; check malloc not NULL
	je alloc_error
	pop rcx 		; unsave mem length
	mov rdi, rax	; copy allocated space for copy
	pop rsi			; unsave mem
	cld				; clear direction flag
	rep movsb		; copy mem to allocated space
	jmp end

alloc_error:
	pop rax
	pop rax
error:
	xor rax, rax
end:
	mov rsp, rbp	; stack cleanup
	pop rbp			;
	ret
