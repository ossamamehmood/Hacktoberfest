import whois

def is_domain_available(domain):
    try:
        w = whois.whois(domain)
        if w.status == None:
            return True
        else:
            return False
    except Exception as e:
        print(f"Error: {e}")
        return False

domain = input("Enter the domain to check (e.g., example.com): ")
if is_domain_available(domain):
    print(f"{domain} is available.")
else:
    print(f"{domain} is taken.")
