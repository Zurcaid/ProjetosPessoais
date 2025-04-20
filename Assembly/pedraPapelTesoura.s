#PROGRAMA:	O programa se trata de um jogo de pedra papel e tesoura
#
#VARIAVEIS:	As funcoes atribuidas por cada registrador
#
# %ebx - Contem a opcao escolhida pelo jogador
# %edi - Contem a posicao da opcao escolhida pelo computador
#
# Espaco de memoria usado:
#	sequencia - contem a sequencia de jogadas escolhida pelo jogador
#

.section .data
# Alocando espaco na memoria pra aluns valores
sequencia: .long 1,2,3,1,2,3,1,2,3,1,2,3	# Lista de jogadas

frase: .ascii "\nEsscolha sua jogada: \0"
.equ FRASE_T, 23
ganhou: .ascii "\nVoce ganhou!\0"
.equ GANHOU_T, 14
perdeu: .ascii "\nVoce perdeu!\0"
.equ PERDEU_T, 14
empate: .ascii "\nEmpatou!\0"
.equ EMPATE_T, 10

.equ SISTEMA, 0x80	# Codigo pra chamar o linux
.equ ESCREVER, 4	# Flag pra escrever em um arquivo
.equ LER, 3		# Flag pra ler de um arquivo
.equ ENCERRAR, 1	# Flag pra encerrar programa

.equ STDIN, 0		# Input do teclado
.equ STDOUT, 1		# Saida do terminal

.section .bss
# Buffer:	Espaco de memoria onde o input vai ser carregado
#
.equ BUFFER_SIZE, 10			# Tamanho do buffer
.lcomm BUFFER_DATA, BUFFER_SIZE		# Criacao do buffer

.section .text
# Para jogar o jogo, sera dado um input ao usuario, que deve responder
# com "pedra", "papel", "tesoura" ou "fim".

.globl _start
_start:

movl $-1, %edi	# Comeca com o index em -1 porque no comeco do loop ele e
		# incrementado
game_loop:	# Loop onde o jogo ira ocorrer
incl %edi		# Aumenta o index

movl $ESCREVER, %eax	# Flag pra escrever em %eax
movl $STDOUT, %ebx	# Flag pra escrever no terminal %ebx
movl $frase, %ecx	# Conteudo do que sera escrito
movl $FRASE_T, %edx	# tamanho da string escrita
int $SISTEMA		# Chama o linux

movl $LER, %eax		# Flag pra ler em %eax
movl $STDIN, %ebx	# Flag pra ler do teclado
movl $BUFFER_DATA, %ecx	# Onde o input sera escrito
movl $BUFFER_SIZE, %edx	# Tamanho do buffer que vai registrar o input
int $SISTEMA		# Chama o linux

movl sequencia(,%edi,4), %ebx	# Salva o valor do computador em %ebx
movb BUFFER_DATA + 2, %al

cmpb $100, %al			# Compara o input com "pedra"
je j_pedra			# Se for igual, va para j_pedra
cmpb $112, %al			# Compara o input com "papel"
je j_papel			# Se for igual, va para j_papel
cmpb $115, %al			# Compara o input com "tesoura"
je j_tesoura			# Se for igual, va para j_tesoura
cmpb $109, %al		 	# Compara o imput com "fim"
je end_loop			# Se for igual va para end_loop

jmp game_loop			# Se chegar aqui, repita o loop

j_pedra:
cmpl $1, %ebx			# Se o computador escolher pedra
je j_empate			# pule para o j_empate
cmpl $2, %ebx			# Se o computador escolher papel
je j_derrota			# va para j_derrota
cmpl $3, %ebx			# Se o computador escolher tesoura
je j_vitoria			# va para j_vitoria

j_papel:			# Mesma coisa que o caso de cima
cmpl $1, %ebx			# alterado pro papel
je j_vitoria
cmpl $2, %ebx
je j_empate
cmpl $3, %ebx
je j_derrota

j_tesoura:			# Mesma coisa pros dois casos
cmpl $1, %ebx			# anteriores alterados pra tesoura
je j_derrota
cmpl $2, %ebx
je j_vitoria
cmpl $3, %ebx
je j_empate

j_vitoria:			# Caso chegue aqui
movl $ganhou, %ecx		# Salve a frase de vitoria em %ecx
movl $GANHOU_T, %edx		# e o tamanho da frase em %edx
jmp resultado			# pule para resultado

j_derrota:			# Caso chegue aqui
movl $perdeu, %ecx		# Salve a frase de derrota em %ecx
movl $PERDEU_T, %edx		# e o tamanho da frase em %edx
jmp resultado			# pule para resultado

j_empate:			# Caso chegue aqui
movl $empate, %ecx		# Salve a frase de empate em %ecx
movl $EMPATE_T, %edx		# e o tamanho da frase em %edx

resultado:
movl $ESCREVER, %eax		# Flag para escrever em %eax
movl $STDOUT, %ebx		# Flag para escrever no terminal em %ebx
int $SISTEMA			# Chama o linux

jmp game_loop			# Retorne ao inicio do loop

end_loop:			# Caso chegue aqui
movl $ENCERRAR, %eax		# Flag para finalizar em %eax
movl $0, %ebx			# Codigo de erro em %ebx
int $SISTEMA			# Chama o linux pra terminar o programa	
