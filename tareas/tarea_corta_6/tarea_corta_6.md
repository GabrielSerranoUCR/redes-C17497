# Tarea corta 6

## Consider routing in a network with 180 routers, and on average every router is connected to 5 other routers. Routing information is exchanged every 120 msec. How much network bandwidth is used under link-state and distance vector routing to exchange this information. Assume sequence numbers are used to damp flood packets for link-state. Please explain any assumptions you make about the size of routing table entries

### Protocolo de enrutamiento distancia-vector
Para el tamaño de cada entrada, podemos asumir tamaños similares a el protocolo distancia-vector de CISCO: IGRP. En este protocolo, cada entrada de la tabla de enrutamiento tiene los siguientes campos:

| Campo| Tamaño (Bytes) |
|------|--------|
Dirección  | 3|
Retraso | 3 |
Ancho de banda | 3
Unidad máxima de transmisión (MTU) | 2
Confiabilidad | 1
Carga | 1
Cantidad de saltos | 1


- Total de bytes utilizado por entrada:  14 bytes.

Cada router debe enviar su tabla a los vecinos, por lo que este caso son 5, y cada tabla tiene una entrada por router, que son 180.

$180\text{ entradas de tabla} \times 14B \times 5 \text{ vecinos} = 12600B $

Y cada router envía esta cantidad, por lo que hay que obtener la cantidad total de bytes enviados:

$12600B \times 180 = 2 268 000B$

que se envían cada 120 milisegundos, o 0.12 segundos, con esto podemos calcular el ancho de banda necesario por segundo:

$\frac{2 268 000B}{0.12s} = 18 900 000B$

Lo que nos da 18900000Bps, o 18.9MBps en en el protocolo de enrutamiento distancia-vector.

### Protocolo estado de enlace

Cada router envía un LSA con la información de sus vecinos a todos los demás routers. Cada LSA tiene:

| Campo| Tamaño (Bytes) |
|------|--------|
Router ID  | 4|
Número de secuencia | 4 |
Vecinos (solo el ID del router) | $4 \times 5$

Por lo que cada LSA es de 28 Bytes. Cada router distribuye 179 LSA entre sus vecinos, que son las que recibió de los demás routers, y su propia LSA a los vecinos, lo que resulta en 180 LSA distribuidas por router.

$180\text{ LSAs} \times 5\text{ vecinos} \times 28B = 25 200B $

por cada router, lo que nos da un total de:

$25200B \times 180 = 4 536 000B$

de Bytes enviados por todos los routers, esto cada 120 milisegundos:

$\frac{4 536 000B}{0.12s} = 37 800 000B$

para un total de ancho de banda de 37800000Bps, o 37.8MBps en el enrutamiento de estado de enlace.

## How can flooding and broadcast be said to be similar to each other? How do they differ? Name one way in which they are similar/different.

Los dos envían un mensaje a todos los nodos en una red. La diferencia es que *flooding* se redirecciona a todas las demás interfaces y es de capa 3, mientras que el broadcast se envía en una dirección de broadcast, y es de capa 2.

## Split horizon does not always help in avoiding the count-to-infinity problem. Illustrate a case where it fails (make routing tables - show 2 iterations).

Cuando se tienen 3 routers, $x$, $y$ y $z$:

Router $x$

| Destino | Siguiente | Costo
|------|--------|---------|
$x$  | | 0
$y$ | $y$ | 1

Router $y$

| Destino | Siguiente | Costo
|------|--------|---------|
$y$  | | 0
$x$ | $x$ | 1
$z$ | $z$ | 1

Router $z$

| Destino | Siguiente | Costo
|------|--------|---------|
$z$  | | 0
$y$ | $y$ | 1

Y falla el enlace $x$-$y$. Ahora, la tabla de routeo de $x$ queda así:

Router $x$

| Destino | Siguiente | Costo
|------|--------|---------|
$x$  | | 0
$y$ | Inválido | $\infty$

### Iteración I

La tabla de routeo de $z$ se ve de la siguiente manera, $z$ no sabe que $y$ no puede llegar a $x$.

Router $z$

| Destino | Siguiente | Costo
|------|--------|---------|
$z$  | | 0
$y$ | $y$ | 1
$x$ | $y$ | 2

Y le notifica a $y$ que él puede llegar a $x$ con costo 2. Entonces la tabla de routeo de $y$ se acualiza:

Router $y$

| Destino | Siguiente | Costo
|------|--------|---------|
$y$  | | 0
$x$ | $z$ | 3
$z$ | $z$ | 1

### Iteración II

$z$ es notificado por $y$ que la ruta para llegar a $x$ ahora cuesta 3 desde $y$, por lo que $z$ actualiza su tabla de routeo:

Router $z$

| Destino | Siguiente | Costo
|------|--------|---------|
$z$  | | 0
$y$ | $y$ | 1
$x$ | $y$ | 4

Ahora cuesta 4 en llegar desde $z$ a $x$, y $z$ le informa a $y$, que actualiza su tabla de routeo:

Router $y$

| Destino | Siguiente | Costo
|------|--------|---------|
$y$  | | 0
$x$ | $z$ | 5
$z$ | $z$ | 1

Y así sigue sumando hasta el infinito.

## Consider the network of Fig. 5-12(a). Distance vector routing is used, and the following link state packets have just come in at router D: from A: (B: 5, E : 4); from B: ( A:4, C: 1, F: 5); from C: (B: 3, D: 4, E: 3); from E: (A: 2, C: 2, F : 2); from F : (B: 1, D:2, E: 3). The cost of the links from D to C and F are 3 and 4 respectively. What is D’s new routing table? Give both the outgoing line to use and the cost.

Los costos de las enlaces de D son:

- D-C: 3
- D-F: 4

Ahora, se observan los paquetes de estado de enlace recibidos por D:

| Desde | Hasta | Costo
|------|--------|---------|
A | B | 5
A | E | 4
B | A | 4
B | C | 1
B | F | 5
C | B | 3
C | D | 4
C | E | 3
E | A | 2
E | C | 2
E | F | 2
F | B | 1
F | D | 2
F | E | 3

Se tiene primeramente la tabla a los vecinos directos:


| Destino | Costo | Siguiente salto |
| ----------- | ---- | -------- |
| C           | 3    | C        |
| F           | 4    | F        |
| D           | 0    | —        |
| A           | $\infty$    | -        |
| B           | $\infty$    | -        |
| E           | $\infty$    | -        |

Se recibe los vectores de distancia de los vecinos:

Desde C:

- B, 3
- D, 4
- E, 3

Desde F:

- B, 1
- D, 2
- E, 3

Utilizando regla Bellman-Ford se actualizan los costos:

Para B:

- Desde C: D-C + C-B = 6
- Desde F: D-F + F-B = 5

Para E:

- Desde C: D-C + C-E = 6
- Desde F: D-F + F-E = 7

Para A:

- Desde C: (D-C + C-E) + E-A = 8

Tabla de costos actualizada:

| Destino | Costo | Siguiente salto |
| ----------- | ---- | -------- |
| A           | 8    | C        |
| B           | 5    | F        |
| C           | 3    | C        |
| D           | 0    | -        |
| E           | 6    | C        |
| F           | 4    | F        |


