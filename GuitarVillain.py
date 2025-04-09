import time
from pynput import keyboard

#Guitar hero no terminal

pont = []
teclas = []

def TeclaPressionada(key):
	if(key.char != 'o'):
		if key.char not in teclas:
			teclas.append(key.char)
	else:
		for j in teclas:
			if(j == '1'):
				if(musicaConfig[screen-9] == 1):
					pont.append(0)
					print("ACERTOU!")
				else:
					pont.pop()
					print("ERROU!")
			elif(j == '2'):
				if(musicaConfig[screen-9] == 2):
					pont.append(0)
					print("ACERTOU!")
				else:
					pont.pop()
					print("ERROU!")
			elif(j == '3'):
				if(musicaConfig[screen-9] == 4):
					pont.append(0)
					print("ACERTOU!")
				else:
					pont.pop()
					print("ERROU!")
			elif(j == '4'):
				if(musicaConfig[screen-9] == 8):
					pont.append(0)
					print("ACERTOU!")
				else:
					pont.pop()
					print("ERROU!")
			elif(j == '5'):
				if(musicaConfig[screen-9] == 16):
					pont.append(0)
					print("ACERTOU!")
				else:
					pont.pop()
					print("ERROU!")

def TeclaSolta(key):
	if key.char in teclas:
		teclas.remove(key.char)


#musicaConfig = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 8, 16, 0, 16, 8, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
musicaConfig = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
#musicaConfig = []
#for i in range(50):
#	musicaConfig.append(1)
# Valores |1|2|4|8|16|
musica = []

for i in musicaConfig: # Conversao dos valores pras teclas
	if i == 0:
		musica.append("| | | | | |")
	elif i == 1:
		musica.append("|X| | | | |")
	elif i == 2:
		musica.append("| |X| | | |")
	elif i == 4:
		musica.append("| | |X| | |")
	elif i == 8:
		musica.append("| | | |X| |")
	elif i == 16:
		musica.append("| | | | |X|")


VerificacaoTecla = keyboard.Listener(on_press=TeclaPressionada, on_release=TeclaSolta)

screen = 9

VerificacaoTecla.start()
while (screen < len(musica)):
	print("----------------")
	for i in range(screen, (screen - 9), -1):
		print(musica[i])
	print(musica[screen - 9], "<---")
	print(teclas)
	time.sleep(0.1)
	screen += 1
VerificacaoTecla.stop()
print("Pontuacao =", len(pont))
