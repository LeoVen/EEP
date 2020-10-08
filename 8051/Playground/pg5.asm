; Passo 1: Selecionar tecla no keypad1
; Passo 2: Acionar a interrupção no keypad2

; Keypad 1
; P0.1 -> Bloquear o sistema de aquecimento
; P0.2 -> Aumentar a temperatura
; P0.3 -> Diminuir a temperatura
; P0.4 -> Estabilizar a temperatura

; Keypad 2
; P3.2 -> Interrupção para leitura da tecla

; P2 -> Display de LED
; A -> P2.0
; B -> P2.1
; C -> P2.2
; D -> P2.3
; E -> P2.4
; F -> P2.5
; G -> P2.6

	org	0x0
	sjmp	prog
	org	0x3
	sjmp	subr1

set_a:	mov	P2, #1110111b	;A
	ret
set_b:	mov	P2, #1111100b	;B
	ret
set_d:	mov	P2, #1011110b	;D
	ret
set_e:	mov	P2, #1111001b	;E
	ret

; Delays
delay:	mov	R0, #0xFF
	djnz	R0, $
	ret

subr1:	clr	EA
	; Rotina 1

	jnb	P0.1, key1
	jnb	P0.2, key2
	jnb	P0.3, key3
	jnb	P0.4, key4

key1:	call	set_b
	sjmp	endr1
key2:	call	set_a
	sjmp	endr1
key3:	call	set_d
	sjmp	endr1
key4:	call	set_e
	sjmp	endr1

endr1:	setb	EA
	reti

; main
prog:
	; Limpar display
	mov	P2, #0

	; Setar as interrupções externas
	setb	EA
	setb	IE.0
	setb	IT0

	sjmp	$
	end
