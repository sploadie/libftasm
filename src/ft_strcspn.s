; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcspn.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/12 17:41:19 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/12 17:56:26 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcspn

section .text

_ft_strcspn:
	cmp rdi, 0
	je error
	cmp rsi, 0
	je error
	mov r9,  rdi		; save s1
	mov r10, rdi
	xor rcx, rcx		; get s2 length
	not rcx
	xor al, al
	mov rdi, rsi
	repne scasb
	not rcx
	mov r11, rcx		; save s2 length
lp_start:
	cmp byte[r10], 0	; exit if s1 done
	je end
	mov al, byte[r10]
	repne scasb
	cmp rcx, 0			; exit if s2 contains *s1
	jne end
	mov rcx, r11
	mov rdi, rsi
	inc r10
	jmp lp_start
end:
	mov rax, r10
	sub rax, r9
	ret
error:
	xor rax, rax
	ret