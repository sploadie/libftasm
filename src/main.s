; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    main.s                                             :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/09/10 12:40:06 by tgauvrit          #+#    #+#              ;
;    Updated: 2016/09/10 12:59:26 by tgauvrit         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _main

extern _puts

section .text

_main:
	push rbp
	; mov rbp, rsp
	; lea rdi, [rel msg]
	mov rdi, msg
	call _puts
	mov rax, 0
	; mov rsp, rbp
	pop rbp
	ret

section .data

msg db "Hello, World!"