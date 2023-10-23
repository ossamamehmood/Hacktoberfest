#!/usr/bin/env python

import nmap, __future__
import sys, os, time, string, datetime
import random, json, pingparsing, cowsay
from module.resultscan import ResultScan 

class Main(ResultScan):

	def checkPing(self, host):
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

	def scanInit(self, ip, args, style):
		GREEN = '\033[92m'
		END = '\033[0m'
		
		response = self.checkPing(ip)
		if  response == True:
			print("Connection..... OK")
			time.sleep(5)
			scan =  nmap.PortScanner()
			result = scan.scan(hosts='{0}' .format(ip), arguments='{0}' .format(args))
			
			printD = ResultScan()
			printD.printDict(result)
			if style == 'yes':
				xml = scan.get_nmap_last_output()
				allchar = string.ascii_letters + string.digits
				random_string = ''.join(random.choice(allchar) for _ in range(1,10) )
				d = datetime.datetime.now()
				date = d.strftime("%d-%m-%y")
				
				with open("Output_Files/scan-{0}-{1}.xml" .format(date ,random_string),'w') as file:
					file.write(xml)
					
				print("\nXML File Scan-{0}-{1}.xml " .format(date ,random_string))
		else:
			print("--------------------------------------")
			print("Please Check Your"+GREEN+" Connetion "+END+"To Target")

	def quickScan(self, ip, port, output):
		if output[0].upper() == 'Y':
			style = '--stylesheet nmap-bootstrap.xsl'
			if port == "":
				args = '--system-dns -sT -T5 {0}'.format(style)
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns -sT -T5 {0} {1}'.format(port_option, style)

			self.scanInit(ip, args, 'yes')
		elif output[0].upper() == 'N':
			if port == "":
				args = '--system-dns -sT -T5'
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns -sT -T5 {0}'.format(port_option)
			self.scanInit(ip, args, 'no')


	def intenceScan(self, ip, port, output):
		if output[0].upper() == 'Y':
			style = '--stylesheet nmap-bootstrap.xsl'
			if port == "":
				args = '--system-dns -sS -A {0}'.format(style)
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns -sS -A {0} {1}'.format(port_option, style)

			self.scanInit(ip, args, 'yes')
		elif output[0].upper() == 'N':
			if port == "":
				args = '--system-dns -sS -A'
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns -sS -A {0}'.format(port_option)

			self.scanInit(ip, args, 'no')

	def scriptScan(self, mode, ip, output):
		if output[0].upper() == 'Y':
			style = '--stylesheet nmap-bootstrap.xsl'
			args = '--system-dns --script {0} {1}'.format(mode, style)
			self.scanInit(ip, args, 'yes')

		elif output[0].upper() == 'N':
			args = '--system-dns --script {0} '.format(mode)
			self.scanInit(ip, args, 'no')

	def typeScan(self, mode, ip, port, output):
		if output[0].upper() == 'Y':
			style = '--stylesheet nmap-bootstrap.xsl'
			if port == "":
				args = '--system-dns {0} {1}'.format(mode, style)
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns {0} {1} {2}'.format(mode, port_option, style)

			self.scanInit(ip, args, 'yes')
		elif output[0].upper() == 'N':
			if port == "":
				args = '--system-dns {0}' .format(mode)
			else:
				port_option = '-p{0}' .format(port)
				args = '--system-dns {0} {1}'.format(mode, port_option)

			self.scanInit(ip, args, 'no')               

	def menu(self, banner, menuTop, scriptMenu, typeMenu, about):
		os.system('clear')
		while True:
			cowsay.dragon(" -Welcome-")
			print(banner)
			try:
				print(menuTop)
				menu = raw_input("Choose Menu : ")
				if menu == '1':
					ip = raw_input("{0} IP Address : " .format("{"+GREEN+"Quick Scan"+END+"}"))
					port = raw_input("{0} Port: " .format("{"+GREEN+"Quick Scan"+END+"}"))
					output = raw_input("{0} Use XML Output ? (Yes/No)" .format("{"+GREEN+"Quick Scan"+END+"}"))
					self.quickScan(ip, port, output)
				elif menu == '2':
					ip = raw_input("{0} IP Address : " .format("{"+GREEN+"Intense Scan"+END+"}"))
					port = raw_input("{0} Port: " .format("{"+GREEN+"Intense Scan"+END+"}"))
					output = raw_input("{0} Use XML Output ? (Yes/No)" .format("{"+GREEN+"Intense Scan"+END+"}"))
					self.intenceScan(ip, port, output)
				elif menu == '3':
					submenu = True
					while submenu:
						print(scriptMenu)
						submenu = raw_input("{0} Choose Script : " .format("{"+GREEN+"Script Scan"+END+"}"))
						name_sub = self.submenuprint(menu, submenu)
						if submenu == '1':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('all', ip, output)
							submenu = False
						elif submenu == '2':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('vuln', ip, output)
							submenu = False
						elif submenu == '3':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('auth', ip, output)
							submenu = False
						elif submenu == '4':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('default', ip, output)
							submenu = False
						elif submenu == '5':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('discovery', ip, output)
							submenu = False
						elif submenu == '6':
							ip = raw_input("{0} IP Address : " .format("Script Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Script Scan{"+GREEN+name_sub+END+"}"))
							self.scriptScan('malware', ip, output)
							submenu = False
						elif submenu == '99':
							submenu = False
						else:
							print("--------------------------------------")
							print("Wrong Menu !!!!")
							print("--------------------------------------")
							raw_input("Press Any Key.....")
				elif menu == '4':
					submenu = True
					while submenu:
						print(typeMenu)
						submenu = raw_input("{0} Choose Type Scan : " .format("{"+GREEN+"Custom Scan"+END+"}"))
						name_sub = self.submenuprint(menu, submenu)
						if submenu == '1':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sS', ip, port, output)
							submenu = False
						elif submenu == '2':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sT', ip, port, output)
							submenu = False
						elif submenu == '3':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sU', ip, port, output)
							submenu = False
						elif submenu == '4':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sN', ip, port, output)
							submenu = False
						elif submenu == '5':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sF', ip, port, output)
							submenu = False
						elif submenu == '6':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sX', ip, port, output)
							submenu = False
						elif submenu == '7':
							ip = raw_input("{0} IP Address : " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							port = raw_input("{0} Port: " .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							output = raw_input("{0} Use XML Output ? (Yes/No)" .format("Custom Scan{"+GREEN+name_sub+END+"}"))
							self.typeScan('-sA', ip, port, output)
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
				raw_input("\nPress Enter To Continue.....")
			except(KeyboardInterrupt):
				print("Exiiiting")
				exit()
			except(ValueError):
				print("--------------------------------------")
				print("Value Error")
				raw_input("\nPress Enter To Continue.....")

	def submenuprint(self, menu,mode):
		if menu == '3':
			if mode == '1':
				return "All"
			elif mode == '2':
				return "Vuln"
			elif mode == '3':
				return "Auth"
			elif mode == '4':
				return "Default"
			elif mode == '5':
				return "Discovery"
			elif mode == '6':
				return "Malware"			
		elif menu == '4':
			if mode == '1':
				return "TCP SYN Scan"
			elif mode == '2':
				return "TCP Connect Scan"
			elif mode == '3':
				return "UDP Scan"
			elif mode == '4':
				return "TCP NULL Scan"
			elif mode == '5':
				return "TCP FIN Scan"
			elif mode == '6':
				return "Xmas Scan"
			elif mode == '7':
				return "TCP ACK Scan"

if __name__ == "__main__":
	if os.geteuid() == 0:
		GREEN = '\033[92m'
		END = '\033[0m'

		banner = GREEN + '''
	<<<||'''+END+'''  .:: Nmap Automation Scanner in Python ::.  '''+GREEN+'''||>>>
	<<<||'''+END+'''            .:: Version: 1.0 ::.             '''+GREEN+'''||>>>
				 
		'''+END

		menuTop = ''' 
	{1} Quick Scan
	{2} Intense Scan
	{3} Script Scan
	{4} Custom Scan
	{5} About
	{6} Exit
		'''

		scriptMenu = ''' 
	{1} All
	{2} Vuln
	{3} Auth
	{4} Default
	{5} Discovery
	{6} Malware
	{99} Back
		'''

		typeMenu = ''' 
	{1} TCP SYN Scan
	{2} TCP Connect Scan
	{3} UDP Scan
	{4} TCP NULL Scan
	{5} TCP FIN Scan
	{6} Xmas Scan
	{7} TCP ACK Scan
	{99} Back
		'''

		about = '''
	<<<|| .:: Nmap Automation Scanner in Python ::. ||>>>
	<<<||            .:: Version: 1.0 ::.           ||>>>
	<<<||          .:: By Vr33d to Cod3 ::.         ||>>>
		'''

		m = Main()
		m.menu(banner, menuTop, scriptMenu, typeMenu, about)
	else:
		sys.exit("Must Run as Root")
