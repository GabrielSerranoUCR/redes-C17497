# Subnetting homework

Assigned network: 192.168.24.0
• Host address requests:
– 16 addresses for range A
– 127 addresses for range B
– 30 addresses for range C
– 15 addresses for range D
– 63 addresses for range E
– 7 addresses for range F
• Task: ordering requests from bigger to lower, and
assigning IP addresses from lower to higher, divide
the original set to satisfy all requests.

## Solución

Primero, se ordenan las petición de mayor a menor:

rango B: original 127, ajustado a 256 ($2^8$).
rango E: original 64, ajustado a 128 ($2^7$).
rango C: original 30, ajustado a 32 ($2^5$).
rango A: original 16, ajustado a 32 ($2^5$).
rango D: original 15, ajustado a 32 ($2^5$).
rango F: original 7, ajustado a 16 ($2^4$).

Total de direcciones necesarias: 512 ($2^9$).

Conjunto más grande primero, IPs más pequeñas primero.

| Set | N   | Net            | Mask         | Broadcast      | First          | Last           |
|-----|-----|----------------|--------------|----------------|----------------|----------------|
| A   | 32  | 192.168.25.128 | 27           | 192.168.25.159 | 192.168.25.129 | 192.168.25.158 |
| B   | 256 | 192.168.24.0   | 24           | 192.168.24.255 | 192.168.24.1   | 192.168.24.254 |
| C   | 32  | 192.168.25.160 | 27           | 192.168.25.191 | 192.168.25.161 | 192.168.25.190 |
| D   | 32  | 192.168.25.192 | 27           | 192.168.25.223 | 192.168.25.193 | 192.168.25.222 |
| E   | 128 | 192.168.25.0   | 25           | 192.168.25.127 | 192.168.25.1   | 192.168.25.126 |
| F   | 16  | 192.168.25.224 | 29           | 192.168.25.239 | 192.168.25.225 | 192.168.25.238 | 