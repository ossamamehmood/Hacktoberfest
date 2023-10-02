import socket

def scan_ip_range(start_ip, end_ip, port):
    try:
        start = list(map(int, start_ip.split('.')))
        end = list(map(int, end_ip.split('.')))

        for i in range(start[0], end[0] + 1):
            for j in range(start[1], end[1] + 1):
                for k in range(start[2], end[2] + 1):
                    for l in range(start[3], end[3] + 1):
                        target_ip = f"{i}.{j}.{k}.{l}"
                        try:
                            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                            sock.settimeout(1)
                            result = sock.connect_ex((target_ip, port))
                            if result == 0:
                                print(f"Port {port} is open on {target_ip}")
                            sock.close()
                        except socket.error:
                            pass

    except KeyboardInterrupt:
        print("\nScan terminated by user")
        exit()
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    start_ip = input("Enter the start IP address (e.g., 192.168.0.1): ")
    end_ip = input("Enter the end IP address (e.g., 192.168.0.254): ")
    port = int(input("Enter the port to scan: "))
    
    scan_ip_range(start_ip, end_ip, port)
