# Tarea corta 7

## Queueing exercise

Hay que modificar el tiempo de finalización de cada paquete de las colas, la cola superior no recibió cambios, por lo que quedan igual. Se calcula con la siguiente formula:

$F_i=max(F_{prev}, A_i) + \frac{L_i}{w}$

Lo importante es que se toma el tiempo mayor entre el tiempo de finalización del paquete anterior en la cola o el tiempo de llegada.

### Cola del medio

### B

$max(5,0) + \frac{6}{2} = 8$

### D

$max(8,8) + \frac{9}{2} = 12.5$

### H

$max(20,12.5) + \frac{8}{2} = 24$

### Cola inferior

### C

$max(5,0) + \frac{10}{1} = 15$

### E

$max(8,15) + \frac{8}{1} = 23$

### G

$max(11,23) + \frac{10}{1} = 33$

### Tabla actualizada

| Paquete | Tiempo de llegada | Tamaño | Tiempo de finalización | Orden de salida |
| ------- | ----------------- | ------ | ---------------------- | --------------- |
| A       | 0                 | 8      | 8                      | 1               |              
| B       | 5                 | 6      | 8                      | 2               |
| C       | 5                 | 10     | 15                     | 4               |
| D       | 8                 | 9      | 12.5                   | 3               |
| E       | 8                 | 8      | 23                     | 6               |
| F       | 10                | 6      | 16                     | 5               |
| G       | 11                | 10     | 33                     | 8               |
| H       | 20                | 8      | 24                     | 7               |

## A computer on a 6-Mbps network is regulated by a token bucket. The token bucket is filled at a rate of 1 Mbps. It is initially filled to capacity with 8 megabits. How long can the computer transmit at the full 6 Mbps?

La cubeta tiene 8 Mb de tokens inicialmente. Se genera 1 Mbps y se consumen 6 Mbps, lo que nos deja un uso neto de 5 Mbps. Para calcular en cuánto tiempo no puede mantener esos 6 Mbps, basta con dividir los 8 Mb almacenados inicialmente entre los Mbps netos.

$\frac{8Mb}{5Mbps} = 1.6s$

La computadora puede transmitir a 6 Mbps por 1.6 segundos antes de que se acaben los tokens.