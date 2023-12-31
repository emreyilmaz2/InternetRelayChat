# InternetRelayChat
### This is the very beginning of the journey of learning socket programming and a small IRC server designed in an object-oriented fashion, specifically tailored for use with the HexChat interface but also available for use on netcat.

### The project is based on the Internet Relay Chat protocol in rfc-1459 and utilizes system socket functions from <sys/socket.h> and polling. It is a higher level communication of processes using ipv4 addresses and the Transmission Control Protocol (TCP/IP). The server is implemented as a single process and a single thread.

### The server supports essential IRC commands such as mode, invite, join, kick, names, nick, notice, part, pass, ping, privmsg, quit, and user. Additionally, the server includes various channel options like 'l', 'k', 'i', 'm', 'n', 'o', which are controllable by channel operators.

<img width="1137" alt="UML Diagram of IRC" src="https://github.com/emreyilmaz2/InternetRelayChat/assets/102359028/51b11d4b-6869-4844-b44f-32324c1de720">
<img width="1180" alt="The basics of how to communicate processes" src="https://github.com/emreyilmaz2/InternetRelayChat/assets/102359028/f65eceac-c44a-4b86-a92b-ca657854a9ba">
