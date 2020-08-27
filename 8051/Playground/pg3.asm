; Example using RS0 and RS1
	org	0
	clr	A
	mov	R0, #0x31
	mov	PSW, #00011000b ; Set RS0 and RS1
	mov	R0, #0x33
	add	A, R0
	clr	RS0
	clr	RS1
	add	A, R0
	SJMP	$
	end
