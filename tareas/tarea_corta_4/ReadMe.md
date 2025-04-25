# Tarea Corta 4

## 2.5 In Fig. 2-5, the left-hand band is narrower than the others. Why?

En la zona de la banda de 0.85 micrones, existe mayor atenuacion de la señal, por lo que el ancho de onda es menor.

## 2.13 Television channels are 6 MHz wide. How many bits/sec can be sent if four-level digital signals are used? Assume a noiseless channel.

Usando el teorema de Nyquist, se obtiene:

$$
\text{Max. data rate} = 2B\times log_2V
$$

$$
= 2 \times 6 \times 10^6 \times log_24
$$

$$
= 24 \times 10^6 = 24Mb/s
$$
 
La cantidad máxima de bits/s es de $24Mb/s$.

## 2.14 If a binary signal is sent over a 3-kHz channel whose signal-to-noise ratio is 20 dB, what is the maximum achievable data rate?

Usando el teorema de Shannon:

$$
\text{Max. data rate} = B\times log_2(1+S/N)
$$

Se convierten los $20dB$ en una razón, que por teoría se sabe que es 100.

$$
\text{Max. data rate} = 3\times 10^3 \times log_2(1+100)
$$

$$
\approx 3\times 6.66 \times 10^3 
$$

$$
\approx 19.98 \times 10^3 \approx 19.98Kb/s
$$

La cantidad máxima de bits/s es de aproximadamente $19.98Kb/s$.

## 2.46 In a typical mobile phone system with hexagonal cells, it is forbidden to reuse a frequency band in an adjacent cell. If 840 frequencies are available, how many can be used in a given cell?

Normalmente, se tiene un búfer de 2 celdas de distancia para reutilizar frecuencias, por lo que significa que se hacen clústers de 7 celdas (celda central + sus adyacentes) simétricas por todo el sistema, por lo que se puede decir que cada celda tiene $\frac{1}{7}$ de las frecuencias totales ($N$).

$$
\text{Frecuencias por celda} = \frac{1}{7} \times N_{total}
$$

$$
= \frac{1}{7} \times 840 = 120
$$

Por lo que cada celda puede utilizar 120 frecuencias.

## 2.48 Make a rough estimate of the number of PCS microcells 100 m in diameter it would take to cover San José (45 square km).

Se calcula primero el área de una microcelda:

$$
A = \pi r^2
$$

$$
= \pi (\frac{100}{2})^2
$$

$$
= \pi \times 2500 \approx 7853.98m^2
$$

Y se divide el área de San José entre el tamaño de las microceldas para obtener la cantidad aproximada:

$$
\text{Cantidad de microceldas} \approx \frac{45 \times 10^6}{7853.98} \approx 5729.58
$$

Por lo que se necesitarían aproximadamente como mínimo 5730 microceldas.

