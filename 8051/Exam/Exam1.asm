	org	0x0
	sjmp	prog
	org	0x3
	sjmp	subr1
	org	0x13
	sjmp	subr2

subr1:	clr	EA		; c + d
	clr	P1.0
	setb	EA
	reti
subr2:	clr	EA
	setb	P1.0
	setb	EA
	reti

prog:	mov	30h, #10h	; a

	mov	DPTR, #1300h	; b
	mov	A, #20h
	movx	@DPTR, A

	setb	EA		; c + d
	setb	IE.0
	setb	IE.2
	setb	IT0
	setb	IT1

	mov	PSW, #00011000b	; e

	mov	A, #30h		; f
	add	A, #50h
	mov	R3, A

	sjmp	$
	end
