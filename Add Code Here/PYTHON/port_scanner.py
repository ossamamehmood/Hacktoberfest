#!/usr/bin/python3
import socket
import sys
import threading
import time
print(50*"-")
print("Port Scanner")
print(50*"-")

usage="[*]How to use- python port_scanner.py TARGET START_PORT END_PORT"

start_time=time.time()

if(len(sys.argv)!=4):
	print(50*"-") 
	print(usage)
	print(50*"-")
	sys.exit()
try:
	host=socket.gethostbyname(sys.argv[1])
except socket.gaierror:
	print("unknown host")
	sys.exit()

host=sys.argv[1]
start_port=int(sys.argv[2])
end_port=int(sys.argv[3])
print(f"scanning results for: {host}")
def portscan(port):
	# print(f"scanning port: {port}")
	sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	socket.setdefaulttimeout(1)
	if not sock.connect_ex((host,port)):
		print(f"port {port} is open")
for port in range(start_port, end_port+1):
	thread=threading.Thread(target=portscan,args=(port,))
	thread.start()

end_time=time.time()
print(f"time elapsed: {end_time-start_time}")
