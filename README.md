Frecuencímetro para ChipKIT
======================
Frecuencimetro que muestra la frecuencia en una pantalla LCD Serial de
Sparkfun.
La señal a medir debe ser cuadrada y estar conectado al pin 75 del Max32, que
corresponde al pin del segundo oscilador.
Utilizamos esta señal como reloj para el temporizador 1.
Usando el temporizador 4, que está ajustado para que interrumpa cada 1/5
segundo (para no desbordar el contador de 16bits), se obtiene el valor del temporizador 1 y calculamos la frecuencia en
Hz multiplicándolo por 5.
