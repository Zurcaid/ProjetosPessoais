#  Assembly x86 (Linux 32bits)
#
#PROGRAMA:	Escreve "Hello World!" no terminal
#

.section .data
text: .asciz "Hello World!\n"
.equ text_size, 13

.equ STDOUT, 1
.equ ESCREVER, 4
.equ FINALIZAR, 1
.equ SISTEMA, 0x80

.section .text

.globl _start
_start: 		# Comeco do programa

hello_world:
movl $ESCREVER, %eax	# Coloca a flag pra escrever no %eax
movl $STDOUT, %ebx	# Coloca a file descriptor do STDOUT no %ebx
movl $text, %ecx	# Coloca a string no %ecx
movl $text_size, %edx	# Coloca o tamanho da string no %edx
int $SISTEMA		# Chama o Linux pra executar o pedido

end_program:
movl $FINALIZAR, %eax	# Coloca a flag pra encerrar o programa no %eax
movl $0, %ebx		# Coloca o codigo de erro no %ebx
int $SISTEMA		# Chama o Linux
