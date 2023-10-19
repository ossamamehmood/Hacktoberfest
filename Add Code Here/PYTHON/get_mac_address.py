import subprocess

def get_mac_address():
    try:
        # Run the 'arp' command to get ARP table entries
        arp_output = subprocess.check_output(['arp', '-a']).decode('utf-8')

        # Find the entry that corresponds to your local IP address
        lines = arp_output.split('\n')
        for line in lines:
            if 'your_local_ip_address' in line:
                # Extract the MAC address from the line
                parts = line.split()
                if len(parts) >= 3:
                    mac_address = parts[1]
                    return mac_address

    except Exception as e:
        print(f"Error: {e}")

    return None

your_local_ip_address = 'your_local_ip_address'  # Replace with your local IP address
mac_address = get_mac_address()

if mac_address:
    print(f"MAC Address for {your_local_ip_address}: {mac_address}")
else:
    print(f"MAC Address for {your_local_ip_address} not found.")
