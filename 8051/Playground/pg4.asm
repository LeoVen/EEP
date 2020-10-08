; LED Display using common cathode
; Using LEDDisplay.vhc
; A -> P2.0
; B -> P2.1
; C -> P2.2
; D -> P2.3
; E -> P2.4
; F -> P2.5
; G -> P2.6

delay:	mov	R0, #0xFF
	djnz	R0, $
	ret

	org	0

start:

	mov	P2, #0111111b	; 0
	call	delay
	mov	P2, #0000110b	;1
	call	delay
	mov	P2, #1011011b	;2
	call	delay
	mov	P2, #1001111b	;3
	call	delay
	mov	P2, #1100110b	;4
	call	delay
	mov	P2, #1101101b	;5
	call	delay
	mov	P2, #1111101b	;6
	call	delay
	mov	P2, #0000111b	;7
	call	delay
	mov	P2, #1111111b	;8
	call	delay
	mov	P2, #1101111b	;9
	call	delay
	mov	P2, #1110111b	;A
	call	delay
	mov	P2, #1111100b	;B
	call	delay
	mov	P2, #0111001b	;C
	call	delay
	mov	P2, #1011110b	;D
	call	delay
	mov	P2, #1111001b	;E
	call	delay
	mov	P2, #1110001b	;F
	call	delay
	sjmp	start

	end
