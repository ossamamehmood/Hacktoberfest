import ipaddress
from ipaddress import IPv4Network, ip_address
from posixpath import split
from sys import prefix
from netaddr import IPAddress

def ValidateIPv4(ip):
    #validate ip is not empty
    if ip == "":
        return False
    
    if len(ip) > 18:
        return False
    
    if len(ip)< 7:
        return False

    # split the ip in 2 parts
    splitIP = ip.split('/')
    ipnum = splitIP[0]
    prefix = splitIP[1]
    # check prefix
    if int(prefix) > 32 or int(prefix) < 0:
        return False
    # split the ip in 4 parts
    splitIP = ipnum.split('.')
    # check if the ip is valid
    if len(splitIP) != 4:
        return False
    for i in splitIP:
        if int(i) > 255 or int(i) < 0:
            return False

    # return the ip adn prefix
    return True


ip = input(
    "Please enter an IP address with a subnet prefix for example 192.168.2.155/25: ")

while ValidateIPv4(ip) == False:
    print("The correct format is [0-255].[0-255].[0-255].[0-255] / [8-31]")
    ip = input(
        "Please enter an IP address with a subnet prefix for example 192.168.2.155/25: ")

    continue

# split the ip in 2 parts
IP_address = ip.split("/")
prefix = IP_address[1]

# split the first ip in 4 parts octets
octets = IP_address[0].split(".")

valid_ip = []
for octet in octets:
    valid_ip.append(int(octet))


# transform the integer list into a binarys
binary_octets = []
for i in valid_ip:
    if i > 10:
        binary_octets.append(bin(i)[2:])
    else:
        binary_octets.append("0000000" + bin(i)[2:])

add = ".".join(IP_address[0].split("."))
binadd = ".".join(binary_octets)

print(f"IP address:\t\t{add} \t\t {binadd}")


# netmask
ip = IPv4Network(ip, strict=False)
netmask = ip.netmask

str_netmask = str(netmask)
str_netmask = str_netmask.split(".")
# convert the netmask to binary
netmask_binary = []
for i in str_netmask:
    if int(i) > 10:
        netmask_binary.append(bin(int(i))[2:])
    else:
        netmask_binary.append("0000000" + bin(int(i))[2:])

netmasbin = ".".join(netmask_binary)

# print the netmask and the binary netmask
print(f"Netmask: \t\t{netmask} \t\t {netmasbin}")


# Wildcard mask
wildcar = ip.hostmask
str_wildcar = str(wildcar)
str_wildcar = str_wildcar.split(".")
  # convert the wildcar to binary
wildcar_binary = []
for i in str_wildcar:
    if int(i) > 10:
        wildcar_binary.append(bin(int(i))[2:])
    else:
        wildcar_binary.append("0000000" + bin(int(i))[2:])

wildcarbin = ".".join(wildcar_binary)

# print the wildcar and the binary wildcar
print(f"Wildcard mask: \t\t{wildcar} \t\t {wildcarbin}")


print("----------------------------------------------------------------------------")
#network address
network = ip.network_address
str_network = str(network)
str_network = str_network.split(".")
# convert the network to binary
network_binary = []
for i in str_network:
    if int(i) > 10:
        network_binary.append(bin(int(i))[2:])
    else:
        network_binary.append("0000000" + bin(int(i))[2:])

networkbin = ".".join(network_binary)

#print the network and the binary network
print(f"Network address: \t{network} \t\t {networkbin}")

#broadcast address
broadcast = ip.broadcast_address
str_brodcast = str(broadcast)
str_brodcast = str_brodcast.split(".")
# convert the broadcast to binary

broadcast_binary = []
for i in str_brodcast:
    if int(i) > 10:
        broadcast_binary.append(bin(int(i))[2:])
    else:
        broadcast_binary.append("0000000" + bin(int(i))[2:])
    
broadcastbin = ".".join(broadcast_binary)
    
#print the broadcast and the binary broadcast
print(f"Broadcast address: \t{broadcast} \t\t {broadcastbin}")

#minimum host address
min_host = ip.broadcast_address +1
str_min_host = str(min_host)
str_min_host = str_min_host.split(".")
# convert the min_host to binary
min_host_binary = []
for i in str_min_host:
    if int(i) > 10:
        min_host_binary.append(bin(int(i))[2:])
    else:
        min_host_binary.append("0000000" + bin(int(i))[2:])
    
min_hostbin = ".".join(min_host_binary)

#print the min_host and the binary min_host
print(f"Minimum host address: \t{min_host} \t\t {min_hostbin}")

#maximum host address

max_host = ip.broadcast_address - 1
str_max_host = str(max_host)
str_max_host = str_max_host.split(".")
# convert the max_host to binary

max_host_binary = []
for i in str_max_host:
    if int(i) > 10:
        max_host_binary.append(bin(int(i))[2:])
    else:
        max_host_binary.append("0000000" + bin(int(i))[2:])
    
max_hostbin = ".".join(max_host_binary)

#print the max_host and the binary max_host
print(f"Maximum host address: \t{max_host} \t\t {max_hostbin}")

#total number of hosts
total_hosts = ip.num_addresses
print(f"Hosts/Net: \t\t{total_hosts}")