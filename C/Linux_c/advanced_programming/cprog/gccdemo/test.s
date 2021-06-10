	.file	"test.c"
	.section	.rodata
.LC2:
	.string	"debug:m=%lf n=%lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	fldl	.LC0
	fstpl	32(%esp)
	fldl	32(%esp)
	fldl	.LC1
	faddp	%st, %st(1)
	fstpl	32(%esp)
	fldl	32(%esp)
	fsqrt
	fucomi	%st(0), %st
	jp	.L4
	fucomi	%st(0), %st
	je	.L2
	fstp	%st(0)
	jmp	.L3
.L4:
	fstp	%st(0)
.L3:
	fldl	32(%esp)
	fstpl	(%esp)
	call	sqrt
.L2:
	fstpl	40(%esp)
	movl	$.LC2, %eax
	fldl	40(%esp)
	fstpl	12(%esp)
	fldl	32(%esp)
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1082341376
	.align 8
.LC1:
	.long	0
	.long	1076101120
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
