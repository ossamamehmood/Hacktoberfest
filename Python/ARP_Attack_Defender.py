import os,sys, subprocess
from time import sleep, time

RED, GREEN, BLUE, YELLOW, WHITE, END= '\033[1;31m', '\033[1;32m', '\033[1;34m', '\033[1;33m', '\033[1;37m', '\033[0m'
spaces = " " * 76 # Only for styling
threshold = 12
mac_dict = {}
time_dict = {}

#Checking for root privilleges
try:
    if os.getuid() != 0:
        print("\n{}[-]{}ERROR: ARPSHIELD requires root privillege to run{}".format(YELLOW,RED,GREEN))
        os._exit(1)
except:
    # Its a windows system
    print("\n{}[-]{}ERROR: ARPSHIELD Cannot run on Windows.{}".format(YELLOW,RED,GREEN))
    sleep(1.5)
    os._exit(1)

# Check if the dependancy requirements are met.
try:
    from scapy.all import sniff
    import netifaces
except:
    print("{}[-]{}Dependency requirements not met".format(YELLOW,RED))
    print("{}[-]{}Exiting Now...".format(YELLOW,RED))
    sleep(0.7)
    sys.exit()

# Logo and credits
sys.stdout.write(GREEN + spaces + """
                  ▄▄▄   ▄▄▄   ▄▄▄   ▄▄▄  ▄▄▄▄▄ ▄ ▄▄▄▄ ▄▄▄    ▄▄▄
                 █ . █ █ . \ █ . █ █ ▄▄█ █ █ █ █ █ ▄▄ █ █   █ ▄ █
                 █   █ █   / █  ▄█ █▄▄ █ █   █ █ █ ▄▄ █ █▄  █ █ █
                 █▄█▄█ █▄\▄\ █▄█   █▄▄▄█ █▄█▄█ █ █▄▄▄ █▄▄▄█ █▄▄▄█
    """ + END + BLUE +
    '\n' + '{}Protects you against ARP Spoof Attacks!{}'.format(RED,BLUE).center(98) +
    '\n' + 'Made With <3 by: {0}Aslam Muhammed ({1}Ash-Shaun{2})'.format(YELLOW, RED, YELLOW).center(104) +
'\n' + 'Version: {}1.0{} \n'.format(YELLOW, END).center(98))
# start main import statements

from scapy.all import *
import netifaces

# Selection on Interface (USER)
available_interface = netifaces.interfaces()
print("")
interface = input(r"{}[-]{}Please select the interface you wish to secure({}):".format(YELLOW,WHITE,available_interface))
if interface not in available_interface:
    print("{}[-]{}Interface {} not Available".format(YELLOW,RED,interface))
    exit()


def give_notification(txt, intf):
    mac = "ARP Spoofing Attack Detected from {}.".format(intf)
    if txt == "self":
        subprocess.call(["notify-send", "-i", "dialog-warning", "ARP Spoofing Detected", "You are being attacked!. \n" + mac])
    elif txt == "network":
        subprocess.call(["notify-send", "-i", "dialog-warning", "ARP Spoofing Detected", "Your network is being attacked!. \n" + mac])
    elif txt == "netcut":
        subprocess.call(["notify-send", "-i", "dialog-warning", "ARP Attack Detected", "Your network is being attacked!. \n" + mac])


# Get IP and MAC of Gateway
def getGateway(txt):
    if txt == "ip":
        try:
            getGateway = sr1(IP(dst="1.1.1.1", ttl=0) / ICMP() / "XXXXXXXXXXX", verbose=False, timeout=2)
            print("{}Gateway IP: {}".format(YELLOW,BLUE) , getGateway.src)
            return getGateway.src

        except:
            print("shit happened")
            return ("192.168.38.2")
    elif txt =="ip_of_selected_interface":
        getGateway = sr1(IP(dst="1.1.1.1", ttl=0) / ICMP() / "XXXXXXXXXXX", verbose=False, timeout=2)
        print("{}Your IP: {}".format(YELLOW,BLUE) , getGateway[IP].dst)
        return getGateway[IP].dst
    else:
        try:
            query = Ether(dst="ff:ff:ff:ff:ff:ff") / ARP(pdst=txt)
            ans, _ = srp(query, timeout=2, verbose=0)
            for _, rcv in ans:
                return(rcv[Ether].src)
                break
        except:
            print("Initialization Failed!")


mac_of_selected_interface = get_if_hwaddr(interface)
gatewayip = getGateway("ip")
gatewaymac = getGateway(gatewayip)
ip_of_selected_interface = getGateway("ip_of_selected_interface")


def check_for_spoof(source, dest, s_mac, gatewaymac, gatewayip):
    print(source,"is at", s_mac)
    # check for packets to router
    if source == ip_of_selected_interface:
        if s_mac == mac_of_selected_interface:
            pass
        else:
            print("ARP attack on you.")
            give_notification("self",s_mac)

    if (source == gatewayip and s_mac != gatewaymac) or (source != gatewayip and s_mac == gatewaymac):
        print ("ARP attack on Gateway")
        give_notification("network", s_mac)

def check_for_spoof_attack(source, dest, s_mac, gatewaymac, gatewayip, d_mac):
    # a = time.time()
    # if d_mac == "00:00:00:00:00:00" or "ff:ff:ff:ff:ff:ff" or "FF:FF:FF:FF:FF:FF":
    #     if s_mac == '00:50:56:c0:00:08':
    #         pass
    #     elif s_mac not in mac_dict:
    #         mac_dict[s_mac] = 0
    #         time_dict[s_mac] = a
    #     else:
    #         mac_dict[s_mac] +=1
    #         b = time.time()
    #         print(mac_dict[s_mac])
    #     if s_mac != '00:50:56:c0:00:08' and mac_dict[s_mac] > threshold:
    #         if (time_dict[s_mac] - b) > 30:
    #             # False alarm Maybe
    #             pass
    #         else:
    #             give_notification("netcut", s_mac)
    if source == gatewayip and s_mac != gatewaymac:
        print("ARP Attack Detected.")
        give_notification("netcut", s_mac)


def process_packets(packet):
    source = packet.psrc
    dest = packet.pdst
    operation = packet.op
    s_mac = packet.hwsrc
    d_mac = packet.hwdst
    #print(source,dest,s_mac,operation)

    if operation == 2:
        check_for_spoof(source,dest,s_mac,gatewaymac, gatewayip)
    else:
        check_for_spoof_attack(source, dest, s_mac, gatewaymac, gatewayip, d_mac)


print("{}Your MAC: {}".format(YELLOW,BLUE), mac_of_selected_interface)
print("{}[-]{}Menu:{}".format(YELLOW,GREEN,WHITE),"\n", "\t1. Start ARP SHIELD \n\t2. Exit")
choice = input("{}[-]{}Enter your choice :".format(YELLOW,WHITE))

if choice == '1':
    os.system("clear")
    print("{}[-]{}ARPSHIELD Started. Any output will be redirected to log file.".format(YELLOW,BLUE))
    sniff(filter="arp",prn=process_packets, store=0 )
elif choice =='2':
    print("{}[-]{}Exiting ARPSHIELD.").format(YELLOW,RED)
    sleep(1.5)
    print("{}Bye!".format(BLUE))
    sleep(1.6)
    exit(101)
else:
    print("{}[-]{}Invalid Choice".format(YELLOW,RED))
    exit(101)
