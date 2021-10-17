import socket
hostname = socket.gethostname()
IPAdress = socket.gethostbyname(hostname)
print(hostname)
print(IPAdress)