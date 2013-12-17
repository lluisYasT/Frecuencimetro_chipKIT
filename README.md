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

La máxima frecuencia que se puede medir es 327675 Hz que ocurre cuando la
cuenta del temporizador 1 alcanza su máximo valor (2^16 - 1) cuando se produce
la interrupción del temporizador 4.

Para aumentar la máxima frecuencia es necesario cambiar el periodo del
temporizador 4 para que genere la interrupción con más frecuencia. Si generara
una interrupción cada 1/10 sec la frecuencia máxima sería 655350 Hz. Haciendo
esto también se reduce la precisión y se reduce el tiempo de obtención.
