import nmap, __future__
import sys, os, time, string, datetime
import random, json, pingparsing



def checkPing(host):
	print("Checking Connection to Target!!!")
	ping_parser = pingparsing.PingParsing()
	transmitter = pingparsing.PingTransmitter()
	transmitter.destination = host
	transmitter.count = 5
	result = transmitter.ping()
	json_check = json.dumps(ping_parser.parse(result).as_dict(), indent=4)
	check = json.loads(json_check)
	if check['packet_receive'] >= 3:
		print("--------------------------------------")
		print("Host {0}". format(check['destination']))
		print("Packet Transmit {0}" .format(check['packet_transmit']))
		print("Packet Receieve {0}" .format(check['packet_receive']))
		print("--------------------------------------")
		return True
	else:
		return False

def scanInit(ip, args, style):
	response = checkPing(ip)
	if  response == True:
		print("Connection..... OK")
		time.sleep(5);
		scan =  nmap.PortScanner()
		result = scan.scan(hosts='{0}' .format(ip), arguments='{0}' .format(args))

		printDict(result)
		if style == 'yes':
			xml = scan.get_nmap_last_output()
			allchar = string.ascii_letters + string.digits
			random_string = ''.join(random.choice(allchar) for _ in range(1,10) )
			d = datetime.datetime.now()
			date = d.strftime("%d-%m-%y")

			file = open("scan-{0}-{1}.xml" .format(date ,random_string),'w')
			file.write(xml)
			file.close()
			print("XML File Scan-{0}-{1}.xml " .format(date ,random_string))
	else:
		print("Please Check Your Connetion To Target")

def quickScan(ip, port, output):
	if output[0].upper() == 'Y':
		style = '--stylesheet nmap-bootstrap.xsl'
		if port == "":
			args = '--system-dns -sT -T5 {0}'.format(style)
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns -sT -T5 {0} {1}'.format(port_option, style)

		scanInit(ip, args, 'yes')
	elif output[0].upper() == 'N':
		if port == "":
			args = '--system-dns -sT -T5'
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns -sT -T5 {0}'.format(port_option)
		scanInit(ip, args, 'no')


def intenceScan(ip, port, output):
	if output[0].upper() == 'Y':
		style = '--stylesheet nmap-bootstrap.xsl'
		if port == "":
			args = '--system-dns -sS -A {0}'.format(style)
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns -sS -A {0} {1}'.format(port_option, style)

		scanInit(ip, args, 'yes')
	elif output[0].upper() == 'N':
		if port == "":
			args = '--system-dns -sS -A'
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns -sS -A {0}'.format(port_option)

		scanInit(ip, args, 'no')

def scriptScan(mode, ip, output):
	if output[0].upper() == 'Y':
		style = '--stylesheet nmap-bootstrap.xsl'
		args = '--system-dns --script {0} {1}'.format(mode, style)
		scanInit(ip, args, 'yes')

	elif output[0].upper() == 'N':
		args = '--system-dns --script {0} '.format(mode)
		scanInit(ip, args, 'no')

def typeScan(mode, ip, port, output):
	if output[0].upper() == 'Y':
		style = '--stylesheet nmap-bootstrap.xsl'
		if port == "":
			args = '--system-dns {0} {1}'.format(mode, style)
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns {0} {1} {2}'.format(mode, port_option, style)

		scanInit(ip, args, 'yes')
	elif output[0].upper() == 'N':
		if port == "":
			args = '--system-dns {0}' .format(mode)
		else:
			port_option = '-p{0}' .format(port)
			args = '--system-dns {0} {1}'.format(mode, port_option)

		scanInit(ip, args, 'no')

def printDict(d):
	for k, v in d.items():
		
		if isinstance(v,dict):
			print("---------------")
			print("[ {0} ]" .format(k))
			print("---------------")
			printDict(v)
		else:
			print("[+] - {0} " .format(k))
			print("--> [ {0} ]" .format(v))

def menu(banner, menuTop, scriptMenu, typeMenu, about):
	os.system('clear')
	menu = True
	while menu:
		print(banner)
		try:
			print(menuTop)
			menu = input("Choose Menu : ")
			if menu == '1':
				ip = input("IP Address : ")
				port = input("Port: ")
				output = input("Use XML Output ? (Yes/No)")
				quickScan(ip, port, output)
			elif menu == '2':
				ip = input("IP Address : ")
				port = input("Port: ")
				output = input("Use XML Output ? (Yes/No)")
				intenceScan(ip, port, output)
			elif menu == '3':
				submenu = True
				while submenu:
					print(scriptMenu)
					submenu = input("Choose Script : ")
					if submenu == '1':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('all', ip, output)
						submenu = False
					elif submenu == '2':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('vuln', ip, output)
						submenu = False
					elif submenu == '3':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('auth', ip, output)
						submenu = False
					elif submenu == '4':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('default', ip, output)
						submenu = False
					elif submenu == '5':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('discovery', ip, output)
						submenu = False
					elif submenu == '6':
						ip = input("IP Address : ")
						output = input("Use XML Output ? (Yes/No)")
						scriptScan('malware', ip, output)
						submenu = False
					elif submenu == '99':
						submenu = False
					else:
						print("--------------------------------------")
						print("Wrong Menu !!!!")
						print("--------------------------------------")
			elif menu == '4':
				submenu = True
				while submenu:
					print(typeMenu)
					submenu = input("Choose Type Scan : ")
					if submenu == '1':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sS', ip, port, output)
						submenu = False
					elif submenu == '2':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sT', ip, port, output)
						submenu = False
					elif submenu == '3':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sU', ip, port, output)
						submenu = False
					elif submenu == '4':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sN', ip, port, output)
						submenu = False
					elif submenu == '5':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sF', ip, port, output)
						submenu = False
					elif submenu == '6':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sX', ip, port, output)
						submenu = False
					elif submenu == '7':
						ip = input("IP Address : ")
						port = input("Port: ")
						output = input("Use XML Output ? (Yes/No)")
						typeScan('-sA', ip, port, output)
						submenu = False
					elif submenu == '99':
						submenu = False
					else:
						print("--------------------------------------")
						print("Wrong Menu !!!!")
						print("--------------------------------------")
			elif menu == '5':
				print(about)
			elif menu == '6':
				print("Bye!!!")
				exit()
			else:
				print("--------------------------------------")
				print("Wrong Menu !!!!")
				print("--------------------------------------")
		except(KeyboardInterrupt):
			print("Exiiiting")
			exit()
	

banner = '''
<<<|| .:: Nmap Automation Scanner in Python ::. ||>>>
<<<||            .:: Version: 1.0 ::.           ||>>>
     
'''

menuTop = ''' 
	1. Quick Scan
	2. Intense Scan
	3. Script Scan
	4. Custom Scan
	5. About
	6. Exit
'''

scriptMenu = ''' 
	1. All
	2. Vuln
	3. Auth
	4. Default
	5. Discovery
	6. Malware
	99. Back
'''

typeMenu = ''' 
	1. TCP SYN Scan
	2. TCP Connect Scan
	3. UDP Scan
	4. TCP NULL Scan
	5. TCP FIN Scan
	6. Xmas Scan
	7. TCP ACK Scan
	99. Back
'''

about = '''
	<<<|| .:: Nmap Automation Scanner in Python ::. ||>>>
	<<<||            .:: Version: 1.0 ::.           ||>>>
	<<<||          .:: By Vr33d to Cod3 ::.         ||>>>
'''

if os.geteuid() == 0:
	menu(banner, menuTop, scriptMenu, typeMenu, about)
else:
	sys.exit("Must Run as Root")