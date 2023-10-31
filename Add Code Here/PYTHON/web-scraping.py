import requests
from bs4 import BeautifulSoup

# The target URL you want to scrape
url = 'https://example.com'

# Send an HTTP request and get the HTML content
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.content, 'html.parser')

    # Find specific elements by their HTML tags and classes
    # For example, find all the links on the page
    links = soup.find_all('a')

    # Print the found links
    for link in links:
        print(link.get('href'))

else:
    # Print an error message if the request was not successful
    print(f"Failed to retrieve the webpage: {response.status_code}")
