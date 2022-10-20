import yaml
from pprint import pprint
from netmiko import ConnectHandler


def read_yaml(yaml_file):
	with open(yaml_file) as f:
		inventory = f.read()

	inventory_dict = yaml.load(inventory)
	return inventory_dict

def device_connection(router_ip):
	device = {
		"device_type" : "cisco_ios",
		"ip" : router_ip,
		"username" : "cisco",
		"password" : "cisco"
	}

	conn = ConnectHandler(**device)
	return conn

def conf_ip(conn, ip_config):
	interface = ip_config['interface']
	ip_addr = ip_config['ip_address']
	config_list = ['interface {}'.format(interface),
				'ip address {}'.format(ip_addr),
				'no shutdown']
	print conn.send_config_set(config_list)

def conf_dhcp(conn, dhcp_config):
	pool = dhcp_config['pool']
	network = dhcp_config['network']
	gateway = dhcp_config['gateway']
	config_list = ['ip dhcp pool {}'.format(pool), 
				'network {}'.format(network),
				'default-router {}'.format(gateway)]
	print conn.send_config_set(config_list)

def conf_ospf(conn, ospf_config):
	area = ospf_config['area']
	network_list = ospf_config['network']
	config_list = ['router ospf 1']
	for network in network_list:
		config_list.append('network {} area {}'.format(network, area))

	print conn.send_config_set(config_list)

def main():
	yaml_file = 'inventory.yaml'
	inventory_dict = read_yaml(yaml_file)
	pprint(inventory_dict)

	for router in inventory_dict['CORE']:

		router_ip = router['host']
		print "-------------------------------"
		print "Configuring {}".format(router_ip)
		print "-------------------------------"
		#connection
		conn = device_connection(router_ip)

		#configure ip address
		ip_config = router['int_config']
		for conf in ip_config:
			conf_ip(conn, conf)

		#configure dhcp
		dhcp_config = router['dhcp_config']
		for config in dhcp_config:
			conf_dhcp(conn, config)

		#configure ospf
		ospf_config = router['ospf_config']
		for config in ospf_config:
			conf_ospf(conn, config)
      
main()