# Software Developed by Shaksham Sinha
# Date : 30th August 2019
# Description : A basic console based Dictionary app

import json
from difflib import get_close_matches

#loading data from data.json file
data = json.load(open("data.json"))

# fucntion to find the word


def translate(word):
    word = word.lower()
    if word in data:
        return data[word]
    elif word.title() in data:
        return data[word.title()]
    elif word.upper() in data:
        return data[word.upper()]
    elif len(get_close_matches(word, data.keys(), cutoff=0.8)) > 0:
        yn = input("Did you mean {} instead? Enter Y if yes N if No: ".format(
            get_close_matches(word, data.keys())[0]))
        if yn.upper() == "Y":
            return data[get_close_matches(word, data.keys())[0]]
        elif yn.upper() == "N":
            return "The word dosent exist. Please double check it again"
        else:
            return "We didn't understad your query."

    else:
        return "The word dosent exit please double check again"


print("Welcome to My Dictionary App :)")

word = input("Enter the word to find its meaning : ")
while word:
    output = translate(word)  #calling the function with parameter "word" which is storing the word entered by user
    if type(output) == list:
        for i in output:
            print(" - " + i)
        print("enter another word or press enter to quit")
        word = input("Enter the word to find its meaning : ")
    else:
        print(output)
        print("enter another word or press enter to quit")
        word = input("Enter the word to find its meaning : ")


