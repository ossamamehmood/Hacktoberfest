#Python code to illustrate parsing of XML files
# importing the required modules
import csv
import requests
import xml.etree.ElementTree as ET

def loadRSS():

	# url of rss feed
	url = 'http://www.hindustantimes.com/rss/topnews/rssfeed.xml'

	# creating HTTP response object from given url
	resp = requests.get(url)

	# saving the xml file
	with open('topnewsfeed.xml', 'wb') as f:
		f.write(resp.content)
		

def parseXML(xmlfile):

	# create element tree object
	tree = ET.parse(xmlfile)

	# get root element
	root = tree.getroot()

	# create empty list for news items
	newsitems = []

	# iterate news items
	for item in root.findall('./channel/item'):

		# empty news dictionary
		news = {}

		# iterate child elements of item
		for child in item:

			# special checking for namespace object content:media
			if child.tag == '{http://search.yahoo.com/mrss/}content':
				news['media'] = child.attrib['url']
			else:
				news[child.tag] = child.text.encode('utf8')

		# append news dictionary to news items list
		newsitems.append(news)
	
	# return news items list
	return newsitems


def savetoCSV(newsitems, filename):

	# specifying the fields for csv file
	fields = ['guid', 'title', 'pubDate', 'description', 'link', 'media']

	# writing to csv file
	with open(filename, 'w') as csvfile:

		# creating a csv dict writer object
		writer = csv.DictWriter(csvfile, fieldnames = fields)

		# writing headers (field names)
		writer.writeheader()

		# writing data rows
		writer.writerows(newsitems)

	
def main():
	# load rss from web to update existing xml file
	loadRSS()

	# parse xml file
	newsitems = parseXML('topnewsfeed.xml')

	# store news items in a csv file
	savetoCSV(newsitems, 'topnews.csv')
	
	
if __name__ == "__main__":

	# calling main function
	main()
