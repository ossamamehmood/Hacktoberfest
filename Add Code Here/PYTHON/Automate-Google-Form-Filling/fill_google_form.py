


import selenium.webdriver as webdriver
from selenium.webdriver.common.by import By

import time


# open an webpage in a browser
browser = webdriver.Chrome()

url = 'https://docs.google.com/forms/d/1ZCdRXdf9c6WLrIF2-bzfXVvDbFn37RQ7-sXv22PW1Ho'
browser.get(url)

# # wait till the page loads completely
time.sleep(1)

# # select the xpath of input field
try:
    email_to_be_filled = 'shantanubombatkar2@gmail.com'
    # fill First Name, Last Name, Email, Check Box, Response, Date
    get_email_inputbox = browser.find_element(
        By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[1]/div/div[1]/div[2]/div[1]/div/div[1]/input')
    get_email_inputbox.send_keys(email_to_be_filled)
    # get_email_inputbox.send_keys(Keys.RETURN)
except:
    print('Email not found')

# # select the xpath of input field for First Name
try:
    get_first_name_inputbox = browser.find_element(
        By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[2]/div/div/div[2]/div/div[1]/div/div[1]/input')
    get_first_name_inputbox.send_keys('Shantanu')
except:
    print('First Name not found')

# Select the xpath of input field for Last Name
try:
    get_last_name_inputbox = browser.find_element(
        By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[3]/div/div/div[2]/div/div[1]/div/div[1]/input')
    get_last_name_inputbox.send_keys('Bombatkar')
except:
    print('Last Name not found')

# Response 1 2 3 4 chosen 1
try:
    one = '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[4]/div/div/div[2]/div[1]/div/span/div/div[1]/label/div/div[1]'
    two = '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[4]/div/div/div[2]/div[1]/div/span/div/div[2]/label/div/div[1]'
    three = '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[4]/div/div/div[2]/div[1]/div/span/div/div[3]/label/div/div[1]'
    four = '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[4]/div/div/div[2]/div[1]/div/span/div/div[4]/label/div/div[1]'

    get_response = browser.find_element(
        By.XPATH, one)
    get_response.click()
except:
    print('Response not found')

# Check Box chosen 1
try:
    checkbox1 = '//*[@id="i34"]'
    checkbox2 = '//*[@id="i33"]'

    get_checkbox = browser.find_element(
        By.XPATH, checkbox1)
    get_checkbox.click()
except:
    print('Checkbox not found')

# Date to be filled
try:
    get_date = browser.find_element(
        By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[6]/div/div/div[2]/div/div/div[2]/div[1]/div/div[1]/input')
    get_date.send_keys('2021-09-21')
except:
    print('Date not found')

#  Submit the form
# try:
#     get_submit_button = browser.find_element(
#         By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[3]/div[1]/div/div/span')
#     get_submit_button.click()
# except:
#     print('Submit button not found')

# # wait till the page loads completely
time.sleep(1)

# # close the browser
# browser.close()
