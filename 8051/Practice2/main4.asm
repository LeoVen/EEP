; Example using Simple Keypad on port 1, bit 0
	org	0

	clr	A
LOOP:	jb	P1.0, $
	inc	A
	mov	P2, A
	call	delay
	jnb	P1.0, $
	sjmp	$

delay:	mov	R0, #0xFF
	djnz	R0, $
	ret

	end
