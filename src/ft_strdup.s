; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/11 17:04:51 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/11 18:20:14 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup

extern _malloc

section .text

_ft_strdup:
	push rbp		; stack prep
	mov rbp, rsp	;

	cmp rdi, 0		; error if NULL
	je error
	push rdi		; save string
	xor rcx, rcx	; get string length
	not rcx
	xor al, al
	repne scasb
	not rcx
	push rcx		; save string length
	mov rdi, rcx	; call malloc with length
	call _malloc
	cmp rax, 0		; check malloc not NULL
	je alloc_error
	pop rcx 		; unsave string length
	mov rdi, rax	; copy allocated space for copy
	pop rsi			; unsave string
	rep movsb		; copy string to allocated space
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
