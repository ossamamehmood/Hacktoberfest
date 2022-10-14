print ("IP finder tool by ASR827 (telegram-@ASR827)")
import time
import socket as s

time.sleep(3.0)
my_hostname = s.gethostname()
print('Your Hostname is: ' + my_hostname)
my_ip = s.gethostbyname(my_hostname)
print('Your Ip Address is: ' + my_ip)
host = 'dealsmagnet.com'
ip = s.gethostbyname(host)
print('The IP Address of ' + host + ' is: '  + ip)
