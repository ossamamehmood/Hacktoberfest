import socket
import time

portlist = {
    "20" : "ftp data transfer",
    "21" : "ftp command control",
    "22" : "ssh",
    "23" : "telnet",
    "25" : "smpt",
    "53" : "dns",
    "80" : "http",
    "110" : "pop3",
    "111" : "rpcbind",
    "119" : "nntp",
    "123" : "ntp",
    "135" : "msrpc",
    "139" : "netbios-ssn",
    "143" : "imap",
    "161" : "snmp",
    "194" : "irc",
    "443" : "https",
    "445" : "microsoft-ds",
    "993" : "imaps",
    "1723" : "pptp",
    "3306" : "mysql",
    "5900" : "vnc",
    "8080" : "http-proxy"
}

def check_port(ip, port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rslt = sock.connect_ex((ip, int(port)))
        sock.close()
        return rslt
    except:
        return 1

def scan(ip):
    open_ports = [] 
    for port in portlist:
        if check_port(ip, port) == 0:
            open_ports.append(port)
    return open_ports

def main():
    open_ports = []
    ip = str(input("Please enter the scanned IP address: "))
    start_time = time.time()
    open_ports = scan(ip)
    dur = round((time.time() - start_time), 2)
    num = len(open_ports)
    print(f"""\n
Scan Results for {ip}
{num} ports are open.
Scan lasted {dur} seconds.
------------------------------------\n""")
    for port in open_ports:
        portval = portlist[port]
        print(f"""{port} ---- {portval}\n""")     
    print("------------------------------------\n")
     
if __name__ == "__main__":
    main()
