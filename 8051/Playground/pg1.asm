; Prints 0xFF to 0x0 in memory region starting at 0x100 of XDATA
	org	0

	mov	DPTR, #0x100	; Starting external memory
	mov	R0, #0xFF	; Loop counter

loop:
	mov	A, R0		; Value that is written to memory
	movx	@DPTR, A
	inc	DPTR
	djnz	R0, loop

	end
