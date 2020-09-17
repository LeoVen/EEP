	org	0
	SJMP	prog
	org	0x3
	mov	R0, #0x10
	reti
prog:
	setb	EA
	SETB	EX0
	SETB	IT0
	SJMP	$
	end
