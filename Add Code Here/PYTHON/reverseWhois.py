from bs4 import BeautifulSoup as bs
import requests
import mechanize
from mechanize import Browser

run = "y"
while run.upper() == "Y":
    url = "https://viewdns.info/reversewhois/?q="
    owner = input("Who do you want to lookup?")
    name = owner.replace(" ","+")
    br = Browser()
    br.set_handle_robots(False)
    br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
    x = br.open(url+name)
    html = x.read()
    soup = bs(html, features="html5lib")
    table = soup.find_all(lambda tag: tag.name=='table')[3]
    c = 0
    if table.findAll('tr')[0].findAll('td')[0].string != 'Domain Name':
        print("{} owns no domains".format(owner))
    else:
        print("{} owns:".format(owner))
        for row in table.findAll('tr')[1:]:
            c+=1
            col = [k for k in row.findAll('td')]
            print("{}) {}".format(c,col[0].string))

    run = input("Do you wish to search again? (y/n)")
