from pynput import keyboard
import time
import os

teclas = []
teclasDebounce = []
teclasValor = 0

musicRecord = open("/home/zurcaid/Documentos/programasPython/GuitarVillain/musicas/WishYouWereHere.txt", "w")
musicRecord.write("")
musicRecord.close()

def TeclaPressionada(key):
	print("Pressionado")
	if key.char not in teclas:
		teclas.append(key.char)
		teclasDebounce.append(key.char)

def TeclaSolta(key):
	if key.char in teclas:
		teclas.remove(key.char)
	if key.char in teclasDebounce:
		teclasDebounce.remove(key.char)

TenthSecond = 100

musicRecord = open("/home/zurcaid/Documentos/programasPython/GuitarVillain/musicas/WishYouWereHere.txt", "a")

Recorder = keyboard.Listener(on_press=TeclaPressionada, on_release=TeclaSolta)

Recorder.start()
os.system("audacious -pH /home/zurcaid/Documentos/programasPython/GuitarVillain/musicas/WishYouWereHere.m4a &")

while TenthSecond > 0:
	print(teclasDebounce)
	if '1' in teclasDebounce:
		teclasValor += 1
	if '2' in teclasDebounce:
		teclasValor += 2
	if '3' in teclasDebounce:
		teclasValor += 4
	if '4' in teclasDebounce:
		teclasValor += 8
	if '5' in teclasDebounce:
		teclasValor += 16

	musicRecord.write(str(teclasValor)+",")
	teclasValor = 0

	teclasDebounce = []
	TenthSecond -= 1
	time.sleep(0.1)

Recorder.stop()
musicRecord.close()

os.system("audacious -s")
os.system("audacious -q")
