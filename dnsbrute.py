import dns.resolver

res = dns.resolver.Resolver()
archive = open("/home/kali/wordlist.txt", "r")
subdomains = archive.read().splitlines()

target = "website.com"

for subdomain in subdomains:
	try:
		sub_target = subdomain + "." + target
		result = res.resolve(sub_target, "A")
		for ip in result:
			print(sub_target, "->", ip)
	except:
		pass
    
