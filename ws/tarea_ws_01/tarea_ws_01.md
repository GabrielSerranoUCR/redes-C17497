# Tarea Wireshark 01

## Exercise One

### a) What is the IP address of the client that initiates the conversation?

En el primer frame, el cliente que inicia la conversación tiene la IPv4 131.247.95.216.

### b) Use the first two packets to identify the server that is going to be contacted. List the common name, and three IP addresses that can be used for the server.

En los dos primeros paquetes, se puede observar el servidor que se está contactando con el nombre común de www.google.com.

En el paquete 2, se puede ver en la respuesta del servidor DNS tres direcciones IP:
- 64.233.161.99
- 64.233.161.104
- 64.233.161.147

### c) What is happening in frames 3, 4, and 5?

Se está realizando el Handshake de la conexión TCP entre servidor y cliente.

### d) What is happening in frames 6 and 7?

En el frame 6, el cliente hace una petición HTTP al servidor de su raíz, y el frame 7 es la respuesta del servidor que recibió el mensaje.

### f) What is happening in frames nine and ten? How are these two frames related?

El frame 9 contiene la página de respuesta al cliente y el frame 10 es la respuesta correcta de el protocolo HTTP.

### g) What happens in packet 11?

En el frame 11, el paquete es una confirmación TCP, igual que el frame 7.

### h) After the initial set of packets is received, the client sends out a new request in packet 12. This occurs automatically without any action by the user. Why does this occur? See the first “hint” to the left.

Es una nueva petición HTTP de una imagen por parte del cliente. La página principal de Google tiene incluído logo.gif, entonces el cliente lo pide automáticamente para cargar la página correctamente.

### i) What is occurring in packets 13 through 22?

El servidor está enviando los datos de logo.gif, con respuestas de confirmación del cliente intercaladas. En el frame 22, cuando termina de enviar envía un mensaje HTTP de respuesta exitosa.

### j) Explain what happens in packets 23 through 26. See the second “hint” to the left.

Igual que el logo, es una petición automática del favicón de la página, necesario en los navegadores.

### k) In one sentence describe what the user was doing (Reading email? Accessing a web page? FTP? Other?).

El usuario entró a google.com.

## Exercise Two

### a) In the first few packets, the client machine is looking up the common name (cname) of a web site to find its IP address. What is the cname of this web site? Give two IP addresses for this web site.

El nombre común del sitio web es yahoo.com, y dos direcciones IP son:

- 216.109.117.109
- 216.109.117.110

### b) How many packets/frames does it take to receive the web page (the answer to the first http get request only)?

10 paquetes por parte del servidor con los datos, con 5 paquetes de confirmación del cliente intercalados y 1 de respuesta exitosa HTTP del servidor.

### c) Does this web site use gzip to compress its data for sending? Does it write cookies? In order to answer these questions, look under the payload for the reassembled packet that represents the web page. This will be the last packet from question b above. Look to see if it has “Content-Encoding” set to gzip, and to see if it has a “Set-Cookie” to write a cookie.

Sí utiliza gzip para comprimir los datos. De la misma manera, sí escribe cookies.

### d) What is happening in packets 26 and 27? Does every component of a web page have to come from the same server? See the Hint to the left.

En el paquete 26, se está pidiendo la dirección IP de una CDN (Red de entrega de contenido de Yahoo). El paquete 27, es la respuesta del DNS.

No necesariamente se necesita que todos los componentes de la página vengan del mismo servidor, para eso hay varios espejos.

### e) In packet 37 we see another DNS query, this time for us.i1.yimg.com. Why does the client need to ask for this IP address? Didn’t we just get this address in packet 26? (This is a trick question; carefully compare the two common names in packet 26 and 37.)

Son distintos servidores, uno es i1 y el otro es js2. La respuesta del paquete 27 no contenía la dirección IP del que pedimos en el 37.

### f) In packet 42 we see a HTTP “Get” statement, and in packet 48 a new HTTP “Get” statement. Why didn’t the system need another DNS request before the second get statement? Click on packet 42 and look in the middle window. Expand the line titled “Hypertext Transfer Protocol” and read the “Host:” line. Compare that line to the “Host:” line for packet 48.

El host en los dos casos es el mismo servidor i1 que pedimos anteriormente en el paquete 37.

### g) Examine packet 139. It is one segment of a PDU that is reassembled with several other segments in packet 160. Look at packets 141, 142, and 143. Are these three packets also part of packet 160? What happens if a set of packets that are supposed to be reassembled do not arrive in a continuous stream or do not arrive in the proper order?

Los paquetes 141, 142 y 143 no son parte del paquete reensamblado en el paquete 160, como lo indica este mismo.

Si los paquetes no llegan en orden, se puede esperar a que lleguen todos antes de reconstruirlo, solo hay problema si un paquete de la secuencia dura mucho en llegar o se pierde.

### h) Return to examine frames 141 and 142. Both of these are graphics (GIF files) from the same source IP address. How does the client know which graphic to match up to each get statement? Hint: Click on each and look in the middle window for the heading line that starts with “Transmission Control Protocol”. What difference do you see in the heading lines for the two files? Return to the original “Get” statements. Can you see the same difference in the “Get” statements?

El tamaño de un paquete es más grande que el otro, sugiriendo dos GIFS de distintos tamaños. Llegan a distintos puertos, tienen un número de secuencia distinto y un número relativo de confirmación distinto.

Al irse a las peticiones de los dos, se puede ver que fueron dos GIFs distintos. El 141 correspondiendo a trfc_bckt.gif y el 142 a answers.gif

## Exercise Three

### a) Compare the destination port in the TCP packet in frame 3 with the destination port in the TCP packet in frame 12. What difference do you see? What does this tell you about the difference in the two requests?

Son distintas direcciones IP que no comparten máscara, por lo que son dos páginas distintas. Sabemos que es verdad debido a las dos peticiones DNS anteriores a los paquetes, siendo los nombres comunes de las páginas www.yahoo.com y my.usf.edu.

### b) Explain what is happening in row “iii” above. Why are there no frames listed for yahoo in row “iii"?

Porque iii) representa la comunicación para el cifrado SSL, que no ocurre en Yahoo.

### Look at the “Info” column on frame 6. It says: “GET / HTTP / 1.1. What is the corresponding Info field for the my.usf.com web request (frame 21)? Why doesn’t it read the same as in frame 6?

Porque la comunicación se realiza con distintos protocolos, en el frame 6 con HTTP, y en el frame 21 con TLSv1.

## Exercise Four