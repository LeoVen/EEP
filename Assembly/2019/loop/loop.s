	.file	"loop.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movl	%ecx, 64(%rsp)
	movq	%rdx, 72(%rsp)
	call	__main
	movl	$0, 44(%rsp)
	movl	$0, 40(%rsp)
	jmp	.L2
.L3:
	movl	40(%rsp), %eax
	imull	40(%rsp), %eax
	addl	%eax, 44(%rsp)
	addl	$1, 40(%rsp)
.L2:
	cmpl	$999, 40(%rsp)
	jle	.L3
	movl	44(%rsp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
;
; gcc loop.c -S -O0 --omit-frame-pointer