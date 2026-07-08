# BCI

Código utilizado no TCC do curso técnico em eletrônica, "Desenvolvimento de um sistema de interface cérebro-máquina baseado na aquisição e processamento de dados de eletroencefalograma".

O trabalho consistiu na confecção de um circuito de EEG (eletroencefalograma) para aquisição dos sinais, modelagem de um headset com eletrodos, e processamento do sinal no arduino.

O sinal cerebral selecionado foi o das ondas alfa no lobo occiptal, por ter validação relativamente simples (amplitude do sinal varia quando o indivíduo fecha ou abre os olhos).
As ondas alfa estão presentes na frequência de 8-13Hz, o código da FFT no arduino tem como objetivo separar a frequência de 10Hz (que seria um valor aproximado), verificar a amplitude desse sinal, e depois controlar uma carga baseado na amplitude do sinal.
