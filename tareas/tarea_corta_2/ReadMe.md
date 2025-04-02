# Tarea Corta II

### Un servidor envia 1024 Mb de datos a un cliente sobre un enlace de 16.4 Mbps con un 2.5% de pérdida de paquetes. El servidor envía los datos en paquetes de 8 Mb y, después de enviar un paquete, espera a recibir el paquete de confirmación de 8 bytes del cliente antes de mandar el siguiente paquete. Si dura 10 minutos la transferencia de datos en ser completada, determine la latencia del enlace.

Primeramente, calculamos la cantidad de paquetes:

$$
\frac{Datos}{Tamaño-Paquete}=\frac{1024}{8}=128
$$

Y tenemos $2.5%$ de probabilidad de pérdida de paquetes, por lo que podemos suponer que:

$$
128*0.025=3.2
$$
$3.2$ paquetes se esperan perder, por lo que vamos a tener que mandar $4$ paquetes adicionales, siendo $132$ paquetes en total.

Ahora, podemos calcular el tiempo que dura cada paquete en mandarse:

$$
\frac{Tamaño-Paquete}{Velocidad-enlace}= \frac{8}{16.4}=0.4878
$$

El tiempo de envío de cada paquete es de 0.4878 segundos.

Cada paquete tiene un paquete de confirmación seguido, que se calcula de la misma forma. Ahora, se tienen que utilizar los bits, puesto que no es la misma unidad. Entonces convertimos $16.4$ Mbps a $16.4 * 10^6$ bps y calculamos el tiempo que dura cada paquete de confirmación en llegar:

$$
\frac{Tamaño-Paquete}{Velocidad-enlace}= \frac{8*8}{16.4 * 10^6}=3.9*10^{-6}
$$

El tiempo que dura el paquete de confirmacion en ser enviado es de $3.9*10^{-6}$ segundos, casi despreciable.

Para saber cuánta latencia hay, sabemos que cada paquete junto a su confirmación dura $10*60/132=4.5454$ segundos en mandarse.

Por lo que sacamos la siguiente fórmula:

$$
T_{total}-(T_{paquete}+T_{confirmacion})=T_{latencia-total}
$$

$$
4.5454-0.4878-3.9*10^{-6}=4.0576
$$

Y tomando en cuenta que es la latencia total de dos paquetes, la dividimos entre $2$ para obtener la latencia del enlace:

$$
\frac{4.0576}{2}=2.0288
$$

Por lo que obtenemos que la latencia del enlace es de $2.0288$ segundos.

## Explique la lógica detrás de la frase "Puedes comprar más ancho de banda, pero no puedes comprar menos latencia"

Básicamente, el ancho de banda lo que permite es mandar/recibir más cantidad de información por segundo, pero la latencia determinado el tiempo en el que va a llegar esa información. Se puede el ancho de banda como un medio de transporte, por ejemplo, un carro. Un carro puede llevar a 5 personas a un destino, mientras que un bus puede llevar a 40. Sin embargo, los dos pueden duran 2 horas llegando al destino. Las 2 horas en este caso sería el destino. Por lo que no podemos hacer que las personas, o en nuestro caso paquetes, lleguen al destino en un tiempo menor que la latencia, lo que podemos hacer es que lleguen más.


## Compare Datagramas con Redes de Circuitos Virtuales con respecto a: establecimiento del circuito, esquema de direccionamiento, routeo, fallo de routeo, calidad de servicio.

### Establecimiento de circuito

Datagrama: No necesita establecimiento.

RCV: Se establece la sesión de conexión solamente durante la sesión.

### Esquema de direccionamiento

Datagrama: Tiene la información completa del destinatario.

RCV: No tiene la información completa, solo el identificador virtual de circuito (VCI).

### Routeo

Datagrama: Puede cambiar durante la sesión.

RCV: Se establece una conexión directa antes de la sesión, por lo que no cambia.

### Fallo de Routeo

Datagrama: El destinatario necesita saber que no le ha llegado alguno de los paquetes. Como los paquetes no siguen una ruta preestablecida, tiende a tener más errores en una red que no sea robusta.

RCV: Tiene una ruta preestablecida, si falla el routeo, se necesita volver a establecer la conexión con una nueva ruta.

### Calidad de servicio

Datagrama: Como no siguen un orden o ruta esperado, la calidad puede variar dependiendo de la ruta tomada del paquete.

RCV: Con rutas preestablecidas, se sabe claramente cuánto va a durar llegando cada paquete, haciendo predecible el sistema.

## Calcular el retraso total al transferir un archivo de 10 Mb de un host 1 a un host 2 (desde el principio hasta que el host 2 reciba hasta el último bit) usando switching de circuito, switching de mensajes y switching de datagramas. El tamaño del datagrama es 75 Kb. Lo siguiente es conocido:

### - La distancia entre los host es de 2000 km.

### - Hay tres routers (nodos) a la misma distancia entre los host.

### - La velocidad de propagación es 200 000 km/s.

### - El ancho de banda de la transmisión es de 1 Mbps.

### - El retraso de procesamiento por nodo es de 100 ms.

### Se obvia el retraso de procesamiento en los host.



El **retraso de propagación** es el tiempo que tarda la señal en viajar de un punto a otro en la red. La fórmula para el retraso de propagación es:

$$
\text{retraso de Propagación} = \frac{\text{Distancia}}{\text{Velocidad de Propagación}}
$$

Dado que hay 3 routers, la distancia total cubierta en la red es de 2000 km. Sin embargo, la señal pasará por 4 enlaces (de Host 1 a Router 1, de Router 1 a Router 2, de Router 2 a Router 3 y finalmente de Router 3 a Host 2). La distancia por enlace es:

$$
\text{Distancia por Enlace} = \frac{2000 \, \text{km}}{4} = 500 \, \text{km}
$$

El retraso de propagación por enlace es:

$$
\text{retraso de Propagación por Enlace} = \frac{500 \, \text{km}}{200,000 \, \text{km/s}} = 2.5 \, \text{ms}
$$

El **retraso de propagación total** para todo el recorrido (4 enlaces) es:

$$
\text{retraso de Propagación Total} = 4 \times 2.5 \, \text{ms} = 10 \, \text{ms}
$$


El **retraso de transmisión** es el tiempo necesario para transmitir todos los bits del archivo a través de la red. La fórmula para el retraso de transmisión es:

$$
\text{retraso de Transmisión} = \frac{\text{Tamaño del Archivo}}{\text{Tasa de Transmisión}}
$$

La tasa de transmisión es 1 Mbps, lo que equivale a \(1 \times 10^6\) bits por segundo. El tamaño del archivo es de 10 Mb, que es \(10 \times 10^6\) bits. Por lo tanto, el retraso de transmisión es:

$$
\text{retraso de Transmisión} = \frac{10 \times 10^6 \, \text{bits}}{1 \times 10^6 \, \text{bits/seg}} = 10 \, \text{segundos}
$$


### 1. **switching por Circuito**

$$
\text{retraso de Procesamiento Total en Nodos} = 3 \times 100 \, \text{ms} = 300 \, \text{ms}
$$

Por lo tanto, el retraso total para la **switching por circuito** es:

$$
\text{retraso Total (switching por Circuito)} = D_{proc} + D_{prop} + D_{trans}
$$

$$
\text{retraso Total (switching por Circuito)} = 10 \, \text{seg} + 10 \, \text{ms} + 300 \, \text{ms}
$$

$$
\text{retraso Total (switching por Circuito)} = 10.31 \, \text{segundos}
$$

### 2. **switching de Mensajes**



$$
\text{retraso Total (switching de Mensajes)} = D_{proc} + D_{prop} + 3*D_{nodos}
$$

$$
\text{retraso Total (switching de Mensajes)} = 10 \, \text{seg} + 10 \, \text{ms} + 3 \times 100 \, \text{ms}
$$

$$
\text{retraso Total (switching de Mensajes)} = 10.31 \, \text{segundos}
$$

### 3. **switching por Datagramas**

$$
\text{Número de Datagramas} = \frac{Tamaño-Archivo}{Tamaño-Datagramas} = \frac{10 \, \text{Mb}}{75 \, \text{kb}} = \frac{10 \times 10^6 \, \text{bits}}{75 \times 10^3 \, \text{bits}} \approx 133.33 \, \text{datagramas}
$$

Redondeamos a 134 datagramas.

Cada datagrama tendrá su propio retraso de transmisión y propagación, y cada uno incurrirá en un retraso de procesamiento en cada uno de los 3 routers. El retraso total para cada datagrama es:

$$
\text{retraso Total por Datagramas} = D_{proc} + D_{prop} + 3*D_{nodos}
$$

El retraso de transmisión para cada datagrama es:

$$
\text{retraso de Transmisión por Datagramas} = \frac{75 \times 10^3 \, \text{bits}}{1 \times 10^6 \, \text{bits/seg}} = 0.075 \, \text{segundos}
$$

El retraso total para la **switching por datagramas** será:

$$
\text{retraso Total (switching por Datagramas)} = D_{proc} + D_{prop} + 3*D_{nodos}
$$

$$
\text{retraso Total (switching por Datagramas)} = 0.075 \, \text{seg} + 10 \, \text{ms} + 3 \times 100 \, \text{ms}
$$

$$
\text{retraso Total (switching por Datagramas)} = 0.075 \, \text{seg} + 0.01 \, \text{seg} + 0.3 \, \text{seg} = 0.385 \, \text{segundos}
$$

Este retraso es por datagrama, y dado que tenemos 134 datagramas, el retraso total será:

$$
\text{retraso Total (switching por Datagramas)} = 134 \times 0.385 \, \text{seg} = 51.49 \, \text{segundos}
$$

## Conclusión:

- **retraso de switching por Circuito**: 10.31 segundos
- **retraso de switching de Mensajes**: 10.31 segundos
- **retraso de switching por Datagramas**: 51.49 segundos