# Packet Tracer - TCP and UDP Communications

## Part 1: Generate Network Traffic in Simulation Mode and View Multiplexing

### What is this called?

Multiplexing. 

### A variety of PDUs appears in the event list in the Simulation Panel. What is the meaning of the different colors?

Each color represents a different protocol.

- Light blue - TCP.
- Red - DNS.
- Purple - HTTP and STMP.


## Part 2: Examine Functionality of the TCP and UDP Protocols

### Why did it take so long for the HTTP PDU to appear?

Because it needs to first establish the TCP connection (three-way handshake) and then send the HTTP PDU.

### What is the section labeled?

TCP.

### Are these communications considered to be reliable?

Yes, it is a TCP connection, and one of its characteristics is the reliability it provides.

## Record the SRC PORT, DEST PORT, SEQUENCE NUM, and ACK NUM values.

- SRC PORT: 1026
- DEST PORT: 80
- SEQUENCE NUM: 1
- ACK NUM: 1

### Which TCP flags are set in this PDU?

The SYN and FIN flags.

### How are the port and sequence numbers different than before?

- SRC PORT: 80
- DEST PORT: 1026
- SEQUENCE NUM: 1
- ACK NUM: 103

### What information is now listed in the TCP section? How are the port and sequence numbers different from the previous two PDUs?

The source and destination ports are swapped, basically meaning a exchange of PDUs. the sequence number is 1 for both, meaning they are the first packet. The acknowledgement number in the first is 1, meaning is the first packet, and the second one is 103, meaning the were various packets received and acknowledged before the reply was sent.

### Are these communications considered to be reliable?

As the connection is still using TCP, is reliable.

### Record the SRC PORT, DEST PORT, SEQUENCE NUM, and ACK NUM values.

- SRC PORT: 1025
- DEST PORT: 21
- SEQUENCE NUM: 1
- ACK NUM: 53

### What is the value in the flag field?

RST.

### How are the port and sequence numbers different than before?

- SRC PORT: 21
- DEST PORT: 1026
- SEQUENCE NUM: 1
- ACK NUM: 1

### How are the port and sequence numbers different from the previous results?

- SRC PORT: 1026
- DEST PORT: 21
- SEQUENCE NUM: 1
- ACK NUM: 1

### What is the message from the server?

Welcome to PT Ftp server

### What is the Layer 4 protocol?

UDP.

### Are these communications considered to be reliable?

No, UDP is not recognized to be reliable.

### Open the Outbound PDU Details tab and find the UDP section of the PDU formats. Record the SRC PORT and DEST PORT values.

- SRC PORT: 1026
- DEST PORT: 53

### Why are there no sequence and acknowledgement numbers?

As a connection-less protocol, there is no tracking of state of communication. It does not ensure delivery.

### How are the port and sequence numbers different than before?

- SRC PORT: 53
- DEST PORT: 1026

### What is the last section of the PDU called? What is the IP address for the name multiserver.pt.ptu?

DNS Answer. The IP address is 192.168.1.254

### What transport layer protocol does email traffic use?

TCP.

### Are these communications considered to be reliable?

Yes, as it is TCP.

### Record the SRC PORT, DEST PORT, SEQUENCE NUM, and ACK NUM values. What is the flag field value?

- SRC PORT: 1028
- DEST PORT: 25
- SEQUENCE NUM: 0
- ACK NUM: 0

The flag field value is 0b00000010.

### How are the port and sequence numbers different than before?

- SRC PORT: 25
- DEST PORT: 1028
- SEQUENCE NUM: 0
- ACK NUM: 1

### How are the port and sequence numbers different from the previous two results?

- SRC PORT: 1028
- DEST PORT: 25
- SEQUENCE NUM: 1
- ACK NUM: 1

### How are the port and sequence numbers different from the previous two PDUs?

- SRC PORT: 1028
- DEST PORT: 25
- SEQUENCE NUM: 1
- ACK NUM: 1

They are the same as the Outgoing PDU Details of the last one.

### What email protocol is associated with TCP port 25? What protocol is associated with TCP port 110?

- PORT 25: Associated with STMP protocol.
- PORT 110: Associated with POP3 protocol.
