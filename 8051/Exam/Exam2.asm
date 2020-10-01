	org	0x0
	sjmp	prog
	org	0x3
	sjmp	subr1
	org	0x13
	sjmp	subr2

; Green  -> P0.0
; Yellow -> P0.1
; Red    -> P0.2
; PRed   -> P0.3
; PGreen -> P0.4


; Rua
set_g:	clr	P0.0
	ret
clr_g:	setb	P0.0
	ret
set_y:	clr	P0.1
	ret
clr_y:	setb	P0.1
	ret
set_r:	clr	P0.2
	ret
clr_r:	setb	P0.2
	ret


; Pedestre
set_pr:	clr	P0.3
	ret
clr_pr:	setb	P0.3
	ret
set_pg:	clr	P0.4
	ret
clr_pg:	setb	P0.4
	ret


; Delays
delay:	mov	R0, #0xFF	; Atribuição Imediata
	djnz	R0, $
	ret
sdelay:	mov	R0, #0x5F
	djnz	R0, $
	ret


subr1:	clr	EA
	; Rotina 1

	call	clr_g
	call	set_y
	call	delay
	call	clr_y
	call	set_r
	call	clr_pr
	call	set_pg

	setb	EA
	reti


subr2:	clr	EA
	; Rotina 2

	mov	R1, #3h
blink:	call	clr_pg
	call	sdelay
	call	set_pg
	call	sdelay
	djnz	R1, blink

	call	clr_pg
	call	set_pr
	call	clr_r
	call	set_g

	setb	EA
	reti

; main
prog:

	; Setar as interrupções externas
	setb	EA
	setb	IE.0
	setb	IE.2
	setb	IT0
	setb	IT1

	; Semaforo começa como verde
	; E vermelho para o pedestre
	call	set_g
	call	set_pr

	sjmp	$
	end
