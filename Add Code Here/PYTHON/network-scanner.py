from scapy.all import ARP, Ether, srp
import socket
import requests
#import nmap
import ping3
from datetime import datetime

target_ip = "192.168.8.0/25"
target_port_range = (1, 1024)

def get_hostname_by_ip(ip_address):
    try:
        hostname = socket.gethostbyaddr(ip_address)[0]
    except socket.herror:
        hostname = "N/A"
    return hostname


def get_vendor_name(mac_address):
    # Extract the first three octets (24 bits) of the MAC address (OUI)
    oui = mac_address.upper().replace(':', '')[:6]
    
    # Retrieve vendor information from the IEEE OUI database
    url = f"https://api.macvendors.com/{oui}"
    try:
        response = requests.get(url)
        if response.status_code == 200:
            return response.text.strip()
        else:
            return "Unknown"
    except requests.exceptions.RequestException:
        return "Error: Unable to retrieve vendor information."

def scan_open_ports(target_ip, port_range):
    open_ports = []
    for port in range(port_range[0], port_range[1] + 1):
        try:
            # Create a socket and attempt to connect to the target device's port
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(1)  # Set a timeout for the connection attempt
            result = s.connect_ex((target_ip, port))

            # If the result is 0, the port is open; otherwise, it's closed or filtered
            if result == 0:
                open_ports.append(port)
            s.close()

        except socket.error:
            pass

    return open_ports

def check_device_status(target_ip):
    try:
        response_time = ping3.ping(target_ip, timeout=2)
        if response_time is not None:
            return f"Device is online. Response time: {response_time} ms"
        else:
            return "Device is offline or unreachable."

    except OSError:
        return "Error: Unable to reach the target device."
    


""" def os_fingerprinting(target_ip):
    nm = nmap.PortScanner()
    nm.scan(hosts=target_ip, arguments="-O")

    if target_ip in nm.all_hosts():
        os_fingerprint = nm[target_ip]['osmatch']
        return os_fingerprint
    else:
        return "Unknown" """







# create ARP packet
start_time = datetime.now()
arp = ARP(pdst=target_ip)
# create the Ether broadcast packet
# ff:ff:ff:ff:ff:ff MAC address indicates broadcasting
ether = Ether(dst="ff:ff:ff:ff:ff:ff")
# stack them
packet = ether/arp

result = srp(packet, timeout=3, verbose=0)[0]

# a list of clients, we will fill this in the upcoming loop
clients = []

for sent, received in result:
    # for each response, append ip and mac address to `clients` list
    clients.append({'ip': received.psrc, 'mac': received.hwsrc})


print("Available devices in the network:")
print("IP" + " "*18+"MAC"+ " "*18+"HOST NAME")
for client in clients:

    device_hostname = get_hostname_by_ip(client['ip'])
    vendor_name = get_vendor_name(client['mac'])
    #open_ports = scan_open_ports(client['ip'], target_port_range)
    #status_result = check_device_status(client['ip'])

    print("{:16}    {}    {:25}  {}".format(client['ip'], client['mac'],device_hostname,vendor_name))  
"""     if open_ports:
        print(f"Open ports on {client['ip']}: {open_ports}")
    else:
        print(f"No open ports found on {client['ip']}.")
    print(status_result+"\n") """




end_time = datetime.now()
total_time = end_time - start_time

print("Scanning completed in: ", total_time)
