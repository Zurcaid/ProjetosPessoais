import time
from pynput import keyboard
import os

#Guitar hero no terminal

pont = []
seq = []
erros = []
teclas = []

b2 = [2, 3, 6, 7, 10, 11, 14, 18, 19, 22, 26]
b3 = [4, 5, 6, 7, 12, 13, 14, 20, 21, 22, 28]
b4 = [8, 9, 10, 11, 12, 13, 14, 24, 25, 26, 28]
b5 = [16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 28]

def TeclaPressionada(key):
	if(key.char != 'o'):
		if key.char not in teclas:
			teclas.append(key.char)
	else:
		for j in teclas:
			if(j == '1'):
				if(musicaConfig[screen-9]%2 != 0) or (musicaConfig[screen-8]%2 != 0) or (musicaConfig[screen-10]%2 != 0):
					pont.append(0)
					seq.append(0)
				else:
					erros.append(0)
					pont.pop()
					seq.clear()
			elif(j == '2'):
				if(musicaConfig[screen-9] in b2) or (musicaConfig[screen-8] in b2) or (musicaConfig[screen-10] in b2):
					pont.append(0)
					seq.append(0)
				else:
					pont.pop()
					seq.clear()
					erros.append()
			elif(j == '3'):
				if(musicaConfig[screen-9] in b3) or (musicaConfig[screen-8] in b3) or (musicaConfig[screen-10] in b3):
					pont.append(0)
					seq.append(0)
				else:
					pont.pop()
					seq.clear()
					erros.append(0)
			elif(j == '4'):
				if(musicaConfig[screen-9] in b4) or (musicaConfig[screen-8] in b4) or (musicaConfig[screen-10] in b4):
					pont.append(0)
					seq.append(0)
				else:
					pont.pop()
					seq.clear()
					erros.append(0)
			elif(j == '5'):
				if(musicaConfig[screen-9] in b5) or (musicaConfig[screen-8] in b5) or (musicaConfig[screen-10] in b5):
					pont.append(0)
					seq.append(0)
				else:
					pont.pop()
					seq.clear
					erros.append(0)

def TeclaSolta(key):
	if key.char in teclas:
		teclas.remove(key.char)

#Config da musica
musicaDoc = open("/home/zurcaid/Documentos/programasPython/GuitarVillain/musicas/CUBErt.txt", "r")
musicaConfig = musicaDoc.read()
musicaDoc.close()
musicaConfig = musicaConfig.split(",")
musicaConfig.pop()
for i in range(len(musicaConfig)):
	musicaConfig[i] = int(musicaConfig[i])

#musicaConfig = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 8, 16, 0, 16, 8, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# Valores |1|2|4|8|16|
musica = []

for i in musicaConfig: # Conversao dos valores pras teclas
	if i == 0:
		musica.append("| | | | | |")
	elif i == 1:
		musica.append("|X| | | | |")
	elif i == 2:
		musica.append("| |X| | | |")
	elif i == 3:
		musica.append("|X|X| | | |")
	elif i == 4:
		musica.append("| | |X| | |")
	elif i == 5:
		musica.append("|X| |X| | |")
	elif i == 6:
		musica.append("| |X|X| | |")
	elif i == 7:
		musica.append("|X|X|X| | |")
	elif i == 8:
		musica.append("| | | |X| |")
	elif i == 9:
		musica.append("|X| | |X| |")
	elif i == 10:
		musica.append("| |X| |X| |")
	elif i == 11:
		musica.append("|X|X| |X| |")
	elif i == 12:
		musica.append("| | |X|X| |")
	elif i == 13:
		musica.append("|X| |X|X| |")
	elif i == 14:
		musica.append("| |X|X|X| |")
	elif i == 16:
		musica.append("| | | | |X|")
	elif i == 17:
		musica.append("|X| | | |X|")
	elif i == 18:
		musica.append("| |X| | |X|")
	elif i == 19:
		musica.append("|X|X| | |X|")
	elif i == 20:
		musica.append("| | |X| |X|")
	elif i == 21:
		musica.append("|X| |X| |X|")
	elif i == 22:
		musica.append("| |X|X| |X|")
	elif i == 24:
		musica.append("| | | |X|X|")
	elif i == 25:
		musica.append("|X| | |X|X|")
	elif i == 26:
		musica.append("| |X| |X|X|")
	elif i == 28:
		musica.append("| | |X|X|X|")


VerificacaoTecla = keyboard.Listener(on_press=TeclaPressionada, on_release=TeclaSolta)

screen = 12

VerificacaoTecla.start()

#Musica
os.system("audacious -pHq /home/zurcaid/Documentos/programasPython/GuitarVillain/musicas/CUBErt.m4a &")

while (screen < len(musica)):
	print("---------------- SEQUENCIA = x"+str(len(seq)), "- ERROS = x" str(len(erros)))
	for i in range(screen, (screen - 9), -1):
		print(musica[i])
	print(musica[screen - 9], "<---")
	print(teclas)
	time.sleep(0.1)
	screen += 1
VerificacaoTecla.stop()
print("Pontuacao =", len(pont))
os.system("audacious -s")

