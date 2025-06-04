# Tarea Corta 8

## In Figure 6-20, suppose that a new flow E is added that takes a path from R1 to R2 to R6. How does the max-min bandwidth allocation change for the five flows?

It only changes the flow `A`, now the bandwidth allocation for `A` is $1/3$. The new flow `E` has a bandwidth allocation of `1/3`.

The new bandwidth allocation for all flow is the following:
| Flow | Bandwidth Allocation |
|------|----------------------|
| `A`  |          $1/3$       |
| `B`  |          $1/3$       |
| `C`  |          $1/3$       |
| `D`  |          $1/3$       |
| `E`  |          $1/3$       |

## Two hosts simultaneously send data through a network with a capacity of 1 Mbps. Host A uses UDP and transmits a 100 bytes packet every 1 msec. Host B generates data with a rate of 600 kbps and uses TCP. Which host will obtain higher throughput?

UDP needed bandwidth:

$100B \times 8 = 800b$

$800b \times 1000 = 800kbps$

TCP needed bandwidth: $600kbps$.

So, the total bandwidth needed is 1.4Mbps, but the network has a capacity of 1Mbps. So, as TCP has congestion control and UDP has not, TCP will reduce the sending rate resulting in a lower bandwidth, while UDP will try to force through the network, roughly achieving the 800kbps due to the TCP host yielding bandwidth to avoid congestion.

## Both UDP and TCP use port numbers to identify the destination entity when delivering a message. Give two reasons why these protocols invented a new abstract ID (port numbers), instead of using process IDs, which already existed when these protocols were designed.

- There was a need for a set of standard ports for listening various requests, as `HTTP` (port 80) or `DNS` (port 53).

- It permits a host to maintain a constant port, likely to a server of a consistent service. If the port was not constant, the client would probably fail connecting or waste time figuring which port to connect to.