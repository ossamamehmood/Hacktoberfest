'''
@Author: hariom09090
'''

import re

def is_valid_website(url):
    # Regular expression pattern to match a basic URL with http:// or https://
    pattern = r"^(https?://)(www\.)?[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(/[\w/.-]*)?$"
    
    # Use re.match to check if the URL matches the pattern
    if re.match(pattern, url):
        return True
    else:
        return False

# Get user input and validate the URL
user_input = input("Enter a URL to validate: ")
if is_valid_website(user_input):
    print(f"The URL '{user_input}' is valid.")
else:
    print(f"The URL '{user_input}' is not valid.")
