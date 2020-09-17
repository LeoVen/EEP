	org	0
	sjmp	prog
sub1:	clr	EA
	clr	P1.0
	acall	delay
	setb	P1.0
	setb	EA
	mov	TH0, #0x9B
	reti

prog:
	setb	EA
	setb	ET0
	mov	TH0, #254
	mov	TL0, #0x30
	mov	TMOD, #00000100b
	setb	TR0
	setb	P1.0
loop:	sjmp	$
delay:
	mov	R0, #0xFF
	djnz	R0, $
	ret
