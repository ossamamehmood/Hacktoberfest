email_address = input(“enter your email address”).strip()
new = email_address.partition(“@”)
print(f”user name {new[0] } and {new[-1]}”)
