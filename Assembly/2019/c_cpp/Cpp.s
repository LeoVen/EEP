	.file	"Cpp.cpp"
	.text
	.globl	_Z6no_resRiS_S_
	.def	_Z6no_resRiS_S_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6no_resRiS_S_
_Z6no_resRiS_S_:
.LFB28:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movq	24(%rbp), %rax
	movl	%edx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB29:
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
	movl	$1, -4(%rbp)
	movl	$2, -8(%rbp)
	movl	$3, -12(%rbp)
	leaq	-12(%rbp), %rcx
	leaq	-8(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_Z6no_resRiS_S_
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
