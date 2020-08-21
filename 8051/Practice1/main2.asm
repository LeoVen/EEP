org 0

;mov	A,	#0x3A
;mov	DPTR,	#0x1200
;movx	@DPTR,	A

mov	DPTR,	#0x1200	; DPTR = 0x1200
movx	A,	@DPTR	; A = *DPTR
mov	0x30,	A	; 0x30 = A

end
