# Tutorial - How to build your own LinkedIn Profile Scraper in 2022

A Selenium LinkedIn scraper that loops through multiple pages and collects profile data.

## What you can use for?

We  can use this to get details from LinkedIn profiles of specific group of people e.g. details of people working as _'Software Engineer'_.

## Getting Started
LinkedIn is one of the largest platform for the professionals. You can reach to people here with similar skills, jobs etc. All the information can be accessed by hand easily here. But if we want to collect profile data on larger scale, then what? We use scraper for this purpose.  
In this article, we are going to build our own LinkedIn scraper.  
For this we need to have **[ Python ]( https://www.python.org/downloads)** & **[ChromeDriver](https://chromedriver.chromium.org/downloads)** in our system.  
While downloading **ChromeDriver**, we must _take care_ of our chrome version. Check your current chrome browser version and download ChromeDriver according to it.  
We will use *Selenium, Webdriver, Selector from parsel, numpy and json(to collect the data).  
  
After the environment setup, open the Python IDLE and import the following:
```python
from selenium.webdriver.common.keys import Keys
from parsel import Selector
from selenium.webdriver.common.by import By
from time import sleep
from webdriver_manager.chrome import ChromeDriverManager
from selenium import webdriver
import numpy as np
import json
```

##### We have to create a .json file to collect our data, the process is as follows:
```python
with open("data.json", "w") as f:
    json.dump([], f)
 ```
#### Now our next step is to sign in into LinkedIn. For this we will use webdriver and automate this process.  
```python
# open webdriver.
driver = webdriver.Chrome(ChromeDriveManager().install())
driver.maximize_window() #to maximize the chrome window.
sleep(0.5)
# to open linkedin
driver.get('https://www.linkedin.com')
sleep(2)
# clicking on the signin button to input email id and password.
driver.find_element(By.XPATH,'//a[@class="nav__button-secondary btn-md btn-secondary-emphasis"]').click()
sleep(2)
```
*The sleep() function suspends (waits) execution of the current thread for a given number of seconds.*  
  
#### Our next move will be to fill login credentials automatically in LinkedIn sign in page. On inspecting the linkedin signin page we will get the XPATH of username and password.
![linkedin login page](https://i.ibb.co/CnjmQH8/link.png) And we will use this to fill the details automatically as follows:
```python
#find the xpath to the username field and input username. Same with password
username_input = driver.find_element(By.XPATH, '//input[@name="session_key"]')
username_input.send_keys('yourmail@gmail.com')
sleep(2)

password_input = driver.find_element(By.ID, 'password')
password_input.send_keys('yourlinkedinpassword')
sleep(2)
```  
#### Now similarly find the XPATH of signin button and use to automatically click on it as follows:
```python
# find xpath to sign in button and click
driver.find_element(By.XPATH, '//div/button[text()="Sign in"]').click()
sleep(2)
```
## Fetching a list of Profiles  
From previous steps and procedure we are done with the process of automation to log in to linkedin.  
Now its turn to search for the profiles whose data we want to collect.  
For this, first of all we have to locate the search bar to perform specific profile search of our demand.
```python
# locate the search bar to perform profile search
search_input = driver.find_element(By.XPATH, '//input[@placeholder="Search"]')
sleep(1)
```  
Now after entering into the search bar its time to fill the search term of our choice. For example, if we want to collect data from profiles of 'Software Engineer', we will search that in search bar.  
Here is the code to automate this process:
```python
# input the search term
search_input.send_keys('software engineer')
search_input.send_keys(Keys.RETURN)
sleep(8)
```
After searching for 'software engineer', we get multiple options like Jobs, People etc. As we are collecting data of people, we will have to filter the search to 'people'. For this, its important to locate the button and then click. This can be done as follows:
```python
# locate the people filter option to specify people only
driver.find_element(By.XPATH, '//button[text() = "People"]').click()
sleep(8)
```  
  
We can now apply more filters also if want. For example, if we want to get 'software engineer' only from United States, we have to apply location filter. We have to type United States first, then then apply filter. The code is:
```python
# specify location as United States
driver.find_element(By.XPATH, '//button[text() = "Locations"]').click()
sleep(8)
location_input = driver.find_element(
    By.XPATH, '//input[@placeholder = "Add a location"]')
# you need to type Unied States first for you to get the drop down list specifying US
location_input.send_keys('United States')
location_input.send_keys(Keys.RETURN)
sleep(4)

# click on the US option and the click the apply filter button
driver.find_element(By.XPATH, '//span[text()="United States"]').click()
sleep(4)

driver.find_elements(
    By.XPATH, '//*[@aria-label="Apply current filter to show results"]')[1].click()
sleep(4)
pages = 0
``` 
# Getting Profile Details 
  #### Now we are done with getting the profile list. Now, we will have to go to every profile appearing and get data from the each profile. As a linkedin search  result there are multiple pages, we will use _while loop_ to loop over the pages. You can specify the number of pages you want scraped to stop the loop. And then we start with a function to write the data to json. Then we load existing data to a dictionary. After that We Join new_data with file_data inside emp_details. Then we Set file's current position at offset. And the last work to again convert it back to json. We have to update the page number everytime so we can stop the loop. We need to click each profile under the search results to collect the profile details. However, once we have scraped all the profiles in first page, we need to go back to the profiles results page. so that the loop can take us to the next page. That's why we're saving the **starting url**.
```python
while True:

    #function to write the data to json
    def write_json(new_data, filename='data.json'):
        with open(filename, 'r+') as file:
            #loading existing data into a dict.
            file_data = json.load(file)
            # Joining new_data with file_data inside emp_details
            file_data.append(new_data)
            # Setting file's current position at offset.
            file.seek(0)
            # converting back to json.
            json.dump(file_data, file, indent=4)

    pages = pages + 1  # updating the page number
    #it will take us to the next page
    starting_url = driver.current_url
```  
  
Now its turn to Get the xpath to each profile and then loop over all the profiles to collect profile data.
```python
profiles = driver.find_elements(
        By.XPATH, '//div[@class="display-flex"]/span/span/a')
    profiles = [profile.get_attribute('href') for profile in profiles]
    for profile in profiles:
        driver.get(profile)
        sleep(4)
        # this helps us use xpath selectors to scrape data
        sel = Selector(text=driver.page_source)
```  
  
Then we have to specify xpaths to the fields you need.
```python
name = sel.xpath(
            '//title/text()').extract_first().split(' | ')[0].split(') ')[1]
        current_company = sel.xpath(
            '//a[@href = "#experience"]/h2/div/text()').extract_first()
        job_title = sel.xpath(
            '//*[@class="text-body-medium break-words"]/text()').extract_first()

        sleep(4)
```  
Now, for education, skills, and experience, if there are more than 3 datapoints, you have to click the "show more" link. And to access the entire collection. We need an if statement for this.  
```python
# education, previous_companies, skills
        secondary_links = driver.find_elements(
            By.XPATH, '//div[contains (@class, "pvs-list__footer-wrapper")]/div/a')  # xpath to the sub-links
        secondary_links = [link.get_attribute(
            'href') for link in secondary_links]  # access the href to be able to click

        # education
        for link in secondary_links:
            if 'education' in link:  # visit the education section to scrape the data if the profile has more than three education data points
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                education = sel.xpath(
                    '//span[contains(@class, "mr1 hoverable-link-text t-bold")]/span[1]/text()').extract()
                education = np.array(education)
                education = np.unique(education).tolist()
                sleep(3)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()  # click the "back" button to go back to profile page
                sleep(3)

            else:
                # else collect the education datapoints specified in the profiles homepage
                sel = Selector(driver.page_source)
                education = sel.xpath(
                    '//span[contains(text(), "Education")]//following::div[1]/ul/li/div//child::span[contains(@class, "mr1 hoverable-link-text t-bold")]/span[1]/text()').extract()
                sleep(3)

            # skills
            if 'skills' in link:  # follows similar style to the education section
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                all_skills = sel.xpath(
                    '//span[contains(@class, "mr1 t-bold")]/span[1]/text()').extract()
                skills = np.array(all_skills)
                skills = np.unique(skills).tolist()
                sleep(4)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()
                sleep(2)

            else:
                sel = Selector(driver.page_source)
                skills = sel.xpath(
                    '//*[contains(text(), "Skills")][1]//following::div[1]//child::span[contains(@class, "mr1 t-bold")]/span[1]/text()').extract()
                sleep(3)

            # experience
            if 'experience' in link:
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                former_companies = sel.xpath(
                    '//span[@class="t-14 t-normal"]//child::span[1]/text()').extract()
                sleep(3)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()
                sleep(3)

            else:
                sel = Selector(driver.page_source)
                companies = sel.xpath(
                    '//span[contains(text(), "Full-time")]/text()')
                for company in companies:
                    former_companies = company.extract().split()[0]
                    sleep(3)
                    if former_companies == "Full-time":
                        sel = Selector(driver.page_source)
                        former_companies = sel.xpath(
                            '//a[@data-field="experience_company_logo"]//child::span[@class="mr1 hoverable-link-text t-bold"]/span[1]/text()')[1:].extract()
                    else:
                        former_companies = company.extract().split()[0]
        print('\n')
        print(name)
        print(current_company)
        print(former_companies)
        print(job_title)
        print(skills)
        print(education)
        print('\n')
```  
Now lets specify the datapoints you need collected and saved to the output file.
```python
write_json({'name': name, 'current_company': current_company, 'former_companies': former_companies,
                    'job_title': job_title, 'skills': skills, 'education': education})
```  
once all the profiles in the first page have been scraped, we need to go back to the results page so we can specify how to click the next page button
```python
driver.get(starting_url)
```  
We have to scroll down to make the "next page" code available.
```python
driver.execute_script("window.scrollTo(0,document.body.scrollHeight)")
    sleep(7)
```
Now, next button should be clicked to get next page of profile results.  
```python
next_page = driver.find_element(By.XPATH, '//button[@aria-label="Next"]')
    next_page.click()
    sleep(6)
    if pages == 100:  # specify the maximum number of pages you want scraped.
        break
```
Now, we have to close while loop.
```python
else:
    driver.quit()
```

### Now, its done, After successful execution of following lines, you can see a .json file in your directory with the details of 'software engineer'.  
  
# Summary
In this tutorial, we used some libraries which are _Selenium, parsel, time, numpy and json._ In this tutorial, we used json to collect all the data collected in a systematic way. This tutorial is completely based on Python , so Python must be in your system. Most important thing about the tutorial is checking the ChromeDriver version. Firstly, check your chrome version by clicking on three dot and then help then about Chrome. E.g. my chrome version is 103.0.5060.134 so I must have to download the Chromedriver of version equals or less than this. And if the chromedriver will be on the location where this python file is being saved that will be great, because in some scenario if it is not taken care it produces error.  
#### Now, as a Summary I am giving the complete code together here. Hoping that you will like this tutorial.
```python
from selenium.webdriver.common.keys import Keys
from parsel import Selector
from selenium.webdriver.common.by import By
from time import sleep
from webdriver_manager.chrome import ChromeDriverManager
from selenium import webdriver
import numpy as np
import json

with open("data.json", "w") as f:
    json.dump([], f)


driver = webdriver.Chrome(ChromeDriverManager().install())
driver.maximize_window()
sleep(0.5)

driver.get('https://www.linkedin.com')
sleep(2)

driver.find_element(
    By.XPATH, '//a[@class="nav__button-secondary btn-md btn-secondary-emphasis"]').click()
sleep(2)

username_input = driver.find_element(By.XPATH, '//input[@name="session_key"]')
username_input.send_keys('your mail id')
sleep(2)

password_input = driver.find_element(By.ID, 'password')
password_input.send_keys('your linkedin password')
sleep(2)

driver.find_element(By.XPATH, '//div/button[text()="Sign in"]').click()
sleep(2)

search_input = driver.find_element(By.XPATH, '//input[@placeholder="Search"]')
sleep(1)

search_input.send_keys('software engineer')
search_input.send_keys(Keys.RETURN)
sleep(8)

driver.find_element(By.XPATH, '//button[text() = "People"]').click()
sleep(8)

driver.find_element(By.XPATH, '//button[text() = "Locations"]').click()
sleep(8)
location_input = driver.find_element(
    By.XPATH, '//input[@placeholder = "Add a location"]')
location_input.send_keys('United States')
location_input.send_keys(Keys.RETURN)
sleep(4)

driver.find_element(By.XPATH, '//span[text()="United States"]').click()
sleep(4)

driver.find_elements(
    By.XPATH, '//*[@aria-label="Apply current filter to show results"]')[1].click()
sleep(4)
pages = 0

while True:

    def write_json(new_data, filename='data.json'):
        with open(filename, 'r+') as file:
            file_data = json.load(file)
            file_data.append(new_data)
            file.seek(0)
            json.dump(file_data, file, indent=4)

    pages = pages + 1
    starting_url = driver.current_url

    profiles = driver.find_elements(
        By.XPATH, '//div[@class="display-flex"]/span/span/a')
    profiles = [profile.get_attribute('href') for profile in profiles]
    for profile in profiles:
        driver.get(profile)
        sleep(4)
        sel = Selector(text=driver.page_source)

        name = sel.xpath(
            '//title/text()').extract_first().split(' | ')[0].split(') ')[1]
        current_company = sel.xpath(
            '//a[@href = "#experience"]/h2/div/text()').extract_first()
        job_title = sel.xpath(
            '//*[@class="text-body-medium break-words"]/text()').extract_first()

        sleep(4)

        secondary_links = driver.find_elements(
            By.XPATH, '//div[contains (@class, "pvs-list__footer-wrapper")]/div/a')  
        secondary_links = [link.get_attribute(
            'href') for link in secondary_links]  

        for link in secondary_links:
            if 'education' in link: 
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                education = sel.xpath(
                    '//span[contains(@class, "mr1 hoverable-link-text t-bold")]/span[1]/text()').extract()
                education = np.array(education)
                education = np.unique(education).tolist()
                sleep(3)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()
                sleep(3)

            else:
                sel = Selector(driver.page_source)
                education = sel.xpath(
                    '//span[contains(text(), "Education")]//following::div[1]/ul/li/div//child::span[contains(@class, "mr1 hoverable-link-text t-bold")]/span[1]/text()').extract()
                sleep(3)

            if 'skills' in link:
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                all_skills = sel.xpath(
                    '//span[contains(@class, "mr1 t-bold")]/span[1]/text()').extract()
                skills = np.array(all_skills)
                skills = np.unique(skills).tolist()
                sleep(4)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()
                sleep(2)

            else:
                sel = Selector(driver.page_source)
                skills = sel.xpath(
                    '//*[contains(text(), "Skills")][1]//following::div[1]//child::span[contains(@class, "mr1 t-bold")]/span[1]/text()').extract()
                sleep(3)

            # experience
            if 'experience' in link:
                driver.get(link)
                sleep(3)

                sel = Selector(driver.page_source)
                former_companies = sel.xpath(
                    '//span[@class="t-14 t-normal"]//child::span[1]/text()').extract()
                sleep(3)

                driver.find_element(
                    By.XPATH, '//*[@aria-label="Back to the main profile page"]').click()
                sleep(3)

            else:
                sel = Selector(driver.page_source)
                companies = sel.xpath(
                    '//span[contains(text(), "Full-time")]/text()')
                for company in companies:
                    former_companies = company.extract().split()[0]
                    sleep(3)
                    if former_companies == "Full-time":
                        sel = Selector(driver.page_source)
                        former_companies = sel.xpath(
                            '//a[@data-field="experience_company_logo"]//child::span[@class="mr1 hoverable-link-text t-bold"]/span[1]/text()')[1:].extract()
                    else:
                        former_companies = company.extract().split()[0]
        print('\n')
        print(name)
        print(current_company)
        print(former_companies)
        print(job_title)
        print(skills)
        print(education)
        print('\n')

        write_json({'name': name, 'current_company': current_company, 'former_companies': former_companies,
                    'job_title': job_title, 'skills': skills, 'education': education})

    driver.get(starting_url)

    driver.execute_script("window.scrollTo(0,document.body.scrollHeight)")
    sleep(7)

    next_page = driver.find_element(By.XPATH, '//button[@aria-label="Next"]')
    next_page.click()
    sleep(6)
    if pages == 100:  
        break

else:
    driver.quit()

```  
# Limitation  
After having a great linkedin scrapper, there is some limitation in this. During the login process it may happen that it asks for captcha verification which is a part of linkedin security. So, in this case you have to refresh the page and try again or pass the captcha.  
  
