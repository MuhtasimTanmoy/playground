# Shopee

### OS
- Process vs Thread
    - Thread is a subset of process
    - A process can create multiple threads
    - A process has its own address space. Threads share the address space of their parent process
    - Expensive to communicate between two processes. Need inter process communication mechanism
    - Cheaper to communicate between two threads
    - Process is heavyweight. Thread is lightweight

- What is Big Endian?
    - Most significant byte stored first (has lowest memory address)
    - Littl endian is opposite

- Inter Process Communication Mechanisms
    - Message passing (will use message queue)
    - Shared memory
    - Pipe: Piping is a process where the output of one process is made the input of another
    - We have seen examples of this from the UNIX command line using $\mid$
    - Semaphore

- [What problems virtual memory solves?](https://youtu.be/qlH4-oHnBb8)
    - Program can be larger than memory or RAM
    - Holes in address space
    - Mapping to ram and disk
    - Solves the problem of security. One program can't access another program's data or kernel's data

- Advantages of paging
  - Using paging we can have non-contiguous memory
  - And we can swap in and out efficiently. in tha page level not the whole

- [TCP (Transmission Control Protocol) vs UDP (User Datagram Protocol)](https://youtu.be/Vdc8TCESIg8)
    - Both of them are Transport layer protocol.
    - TCP is connection oriented handshake in time of goodbye). 
    - UDP is connection less.
    - In TCP we can't control when data will be sent (3 way handshake to connection set up)
    - TCP packet size is big (Bigger header). 
    - UDP packet size is small (Smaller header). (It might wait for the network to be congestion free). 
    - In UDP we have more control over when data is sent. This is why UDP is used in real time communication. (For example, video chat over skype, real time footbal match streaming. We can't tolerate latency there.)
    - In TCP if we don't get acknowledgement within some time that packet is received INCORRECTLY, packet is retransmitted. UDP does not care about packet loss, erroneous packet.
    -  In TCP packets have segment number. Even if packets are delivered out of order, TCP will rearrange them before sending it to the Application layer.
    - UDP does not guarantee in order packet delivery.
    - TCP has congestion control. No congestion control in UDP.
    -  To sum up TCP is heavyweight but reliable. UDP is lightweight but unreliable.
    - It can also be used in small transactions of information. For example DNS lookup.

## [TCP congestion control](https://youtu.be/uEN-71R4gjQ)
Congestion control has two parts.
- Increase Algorithm
- Decrease Algorithhm

- Congestion window
  - (cwnd): lastByteSent - lastByteAcked <= cwnd

 Slow start: Exponential increment. It continues up to reaching ssthresh.
 Congestion avoidance phase: It starts after reaching ssthresh. Additive increase
 Congestion detection phase: After detecting packet drop. Set ssthresh = cwnd/2,
 cwnd = 1. Start slow start.

 [How TCP handles out of order packet arrival?](https://youtu.be/YttGlOUFDvU)

## Basics of [proxy server](https://youtu.be/qU0PVSJCKcs)
  - Obscure client IP address, protect client
  - Block malicious traffic ( can protect from hacker, virus )
  - Block sites
  - Log activity
  - Improve performance
  - Improve performance ( via caching )


## [TCP connection setup](https://youtu.be/F27PLin3TV0)
- [Who first sets tcp `FIN` flag in client-server connection?](https://stackoverflow.com/questions/4677925/who-first-sets-tcp-fin-flag-in-client-server)
 - https://youtu.be/SzSXHv8RKdM


## [HyperText Transfer Protocol](https://youtu.be/rBm6eoFK28Q)
- Client/ Server Model
- Request/ Response Model
- Stateless
  - Gives us notion of State using Session / Cookie
- Application layer protocol
- Some `http` methods
  - GET
  - POST
  - PUT
  - DELETE
- Server gives back server status code
- There are headers in reqeust and response

## [OSI reference model]( https://youtu.be/i9RL5jD9cTI)
- OSI reference model is more theoritical compared to TCP/IP model.
- https://youtu.be/dkhOZOmV7Fo
- https://youtu.be/pVmUWhQv6yM

Basic idea is :
- There will be a single master and one or more slaves. We will write to master. Then change will propagate to slaves. We will read from slaves.
- Advantage:
  - Query will be faster.
  - In case of a database copy get corrupted, we have backups.
- Disadvantage:
  - Write is now more heavyweight.
  - There is a replication lag (It takes some time to change to be reflected in slaves).

## [Transaction isolation and violations](https://youtu.be/-gxyut1VLcs)
## [Hashing vs Encryption](https://youtu.be/8ZtInClXe1Q)
## [SSL/TLS handshake](https://youtu.be/sEkw8ZcxtFk)
## [How to get a digital certificate from certificate authority?](https://www.youtube.com/watch?v=33VYnE7Bzpk)
## [SSL](https://youtu.be/qXLD2UHq2vk)
  - https://security.stackexchange.com/questions/56389/ssl-certificate-framework-101-how- does-the-browser-actually-verify-the-validity
  - https://youtu.be/heacxYUnFHA
  - https://youtu.be/LPxeYtMDxl0
  - https://youtu.be/qXLD2UHq2vk

## [Distributed Denial of Service](http://www.security-faqs.com/dos-vs-ddos-what-is-the-difference.html)

 https://youtu.be/ilhGh9CEIwM

 In DoS one computer and internet connection is used to flood a target server/networ
 with requests/packets.
 In DDoS instead of one computer and one internet connection the DDoS attack
 utilises many computers and many connections. The attackers are collectively called
  botnet
    it is a bot.
(network of bots).
Ways to prevent DDoS attack:
If the service is used by a human after having many requests we can check whether
(Like
asking select the images with cars)
 After having many requests from a particular address we can block it for some time.
Need to add more things in this section of preventing )