import matplotlib.pyplot as plt
import numpy as np
from numpy.fft import fft, ifft

# DEFINICAO DOS VALORES DO SINAL DE ENTRADA

# sampling rate
sr = 2000
# sampling interval
ts = 1.0/sr
t = np.arange(0,1,ts)

# ADICAO DOS COMPONENTES DO SINAL

freq = 1. # FREQUENCIA DE 1 Hz
x = 3*np.sin(2*np.pi*freq*t)

freq = 4 # FREQUENCIA DE 4 Hz
x += np.sin(2*np.pi*freq*t)

freq = 7 # FREQUENCIA DE 7 Hz
x += 0.5* np.sin(2*np.pi*freq*t)

# CONFIGURACAO DA FFT

X = fft(x)
N = len(X)
n = np.arange(N)
T = N/sr
freq = n/T

# GRAFICOS

plt.figure(figsize = (12, 6))
#GRAFICO FFT
plt.subplot(121)
plt.stem(freq, np.abs(X), 'b', markerfmt=" ", basefmt="-b")
plt.xlabel('Freq (Hz)')
plt.ylabel('FFT Amplitude |X(freq)|')
plt.xlim(0, 10)
#GRAFICO DO SINAL ORIGINAL
plt.subplot(122)
plt.plot(t, ifft(X), 'r')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.tight_layout()
plt.show()
