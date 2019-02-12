	.file	"prog.c"
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
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movl	$0, -4(%rbp)     ; int sum
	movl	$0, -8(%rbp)     ; int i (inside loop)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax   ; move i to eax
	imull	-8(%rbp), %eax   ; i * i
	addl	%eax, -4(%rbp)   ; add eax to sum
	addl	$1, -8(%rbp)     ; i++
.L2:
	cmpl	$999, -8(%rbp)   ; compare long 999 with i
	jle	.L3                  ; jump if less or equals 999
	movl	-4(%rbp), %eax   ; move sum to eax
	movl	%eax, %edx       ; prepares to print
	leaq	.LC0(%rip), %rcx ; -----------------
	call	printf           ; prints
	movl	$0, %eax         ; return 0
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
