# Trabajo práctico en Packet Tracer 03

## RIP

### From the R2 router, how many ICMP messages are successful when pinging PC1?
4.
### From the R2 router, how many ICMP messages are successful when pinging PC4?
0.
### From the PC1, is it possible to ping PC2?
Sí.
### What is the success rate?
75%.
### From the PC1, is it possible to ping PC3?
Sí.
### What is the success rate?
75%.
### From the PC1, is it possible to ping PC4?
No.
### What is the success rate?
0%.
### From the PC4, is it possible to ping PC2?
No.
### What is the success rate?
0%.
### From the PC4, is it possible to ping PC3?
No.
### What is the success rate?
0%.
### What entries are included in the RIP updates sent out from R3?
- 172.30.100.0/24 via 0.0.0.0, metric 1, tag 0
- 172.30.110.0/24 via 0.0.0.0, metric 1, tag 0
- 172.30.200.16/28 via 0.0.0.0, metric 1, tag 0
### On R2, what routes are in the RIP updates that are received from R3?
- 172.30.0.0/16 via 0.0.0.0 in 1 hops
### What entries are included in the RIP updates sent out from R1?
- 172.30.1.0/24 via 0.0.0.0, metric 1, tag 0
- 172.30.2.0/24 via 0.0.0.0, metric 1, tag 0
### On R2, what routes are in the RIP updates that are received from R1?
- 172.30.1.0/24 via 0.0.0.0 in 1 hops
- 172.30.2.0/24 via 0.0.0.0 in 1 hops
### Are the subnet masks now included in the routing updates?
Sí.
### From R2, how many ICMP messages are successful when pinging PC1?
5/5.
### From R2, how many ICMP messages are successful when pinging PC4?
0/5.
### From PC1, is it possible to ping PC2?
Sí.
### What is the success rate?
100%.
### From PC1, is it possible to ping PC3?
Sí.
### What is the success rate?
100%.
### From PC1, is it possible to ping PC4?
No.
### What is the success rate?
0%.
### From PC4, is it possible to ping PC2?
No.
### What is the success rate?
0%.
### From PC4, is it possible to ping PC3?
No.
### What is the success rate?
0%.

## OSPF Configuration

### What is the router ID for R1? 
10.1.1.1
### What is the router ID for R2? 
10.2.2.2
### What is the router ID for R3? 
10.3.3.3
### When the router is reloaded, what is the router ID for R1?
10.1.1.1
### When the router is reloaded, what is the router ID for R2?
10.2.2.2
### When the router is reloaded, what is the router ID for R3?
10.3.3.3