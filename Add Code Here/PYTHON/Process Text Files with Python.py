#! /usr/bin/env python3

#import necessary python modules
import os
import requests

#Variable declaration
path = '/data/feedback/'
myLink = 'http://<External-IP-Address>/feedback/'
myFiles = os.listdir(path)

#Enter for-loop to process files
for file in myFiles:
        #Open files and process data within
        myData = open(path + file)
        iData = myData.read().split('\n')

        #Create dictionary of the retreaved data
        myDictionary = {"title":iData[0], "name":iData[1], "date":iData[2], "feedback":iData[3]}

        #Upload the feedback to the website
        response = requests.post(myLink, json=myDictionary)

        #Close the files
        myData.close()

print(response.status_code)







#! /usr/bin/env python3

import os
import requests

def website(path):
    data = {"title":"", "name":"", "date": "", "feedback": ""}
    for files in os.listdir(path):
        with open((os.path.join(path,files))) as f:
            list_lines = []
            for lines in f:
                list_lines.append(lines.strip())
            data['title'] = list_lines[0]
            data['name'] = list_lines[1]
            data['date'] = list_lines[2]
            data['feedback'] = list_lines[3]
        response = requests.post("http://35.192.145.90/feedback/",json=data)
        print(response.request.body)
        print(response.raise_for_status())

if __name__ == "__main__":
    website("/data/feedback/")