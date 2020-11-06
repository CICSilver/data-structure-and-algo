	.file	"_1207_uniqueOccurrences.c"
	.section	.rodata
.LC0:
	.string	"1.%d\n"
.LC1:
	.string	"2.%d\n"
	.text
	.globl	uniqueOccurrences
	.type	uniqueOccurrences, @function
uniqueOccurrences:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$144, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%rdi, -120(%rbp)
	movl	%esi, -124(%rbp)
	movq	%rsp, %rax
	movq	%rax, %r12
	movl	$2001, -48(%rbp)
	movl	-48(%rbp), %ecx
	movslq	%ecx, %rax
	subq	$1, %rax
	movq	%rax, -56(%rbp)
	movslq	%ecx, %rax
	movq	%rax, -144(%rbp)
	movq	$0, -136(%rbp)
	movslq	%ecx, %rax
	movq	%rax, -160(%rbp)
	movq	$0, -152(%rbp)
	movslq	%ecx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	movl	-124(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -80(%rbp)
	movslq	%ecx, %rax
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	$0, -36(%rbp)
	movl	$0, -40(%rbp)
	jmp	.L2
.L4:
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leal	1000(%rax), %edx
	movq	-64(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	testl	%eax, %eax
	jne	.L3
	movl	-36(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -36(%rbp)
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-120(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %ecx
	movq	-80(%rbp), %rdx
	cltq
	movl	%ecx, (%rdx,%rax,4)
.L3:
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-120(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	addl	$1000, %eax
	movq	-64(%rbp), %rdx
	movslq	%eax, %rcx
	movl	(%rdx,%rcx,4), %edx
	leal	1(%rdx), %ecx
	movq	-64(%rbp), %rdx
	cltq
	movl	%ecx, (%rdx,%rax,4)
	addl	$1, -40(%rbp)
.L2:
	movl	-40(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jl	.L4
	movl	-36(%rbp), %eax
	movq	%rsp, %rdx
	movq	%rdx, %rbx
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -88(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -176(%rbp)
	movq	$0, -168(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r13
	movl	$0, %r14d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	movl	$0, -44(%rbp)
	jmp	.L5
.L6:
	movq	-80(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax

	addl	$1000, %eax
	
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-64(%rbp), %rax
	movl	-100(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movq	-96(%rbp), %rdx
	movslq	%eax, %rcx
	movl	(%rdx,%rcx,4), %edx
	leal	1(%rdx), %ecx
	movq	-96(%rbp), %rdx
	cltq
	movl	%ecx, (%rdx,%rax,4)
	movl	-100(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -44(%rbp)
.L5:
	movl	-44(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L6
	movl	$1, %eax
	movq	%rbx, %rsp
	movq	%r12, %rsp
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	uniqueOccurrences, .-uniqueOccurrences
	.section	.rodata
.LC2:
	.string	"\n%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$-1, -32(%rbp)
	movl	$-1, -28(%rbp)
	movl	$-1, -24(%rbp)
	movl	$-3, -20(%rbp)
	movl	$-1, -16(%rbp)
	movl	$-1, -12(%rbp)
	leaq	-32(%rbp), %rax
	movl	$6, %esi
	movq	%rax, %rdi
	call	uniqueOccurrences
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.4.0"
	.section	.note.GNU-stack,"",@progbits
