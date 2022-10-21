import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import smtplib
import os
import time
import random
from googletrans import Translator

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1])
engine.setProperty('voice', voices[0].id)

chrome_path = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"
webbrowser.register('chrome', None,webbrowser.BackgroundBrowser(chrome_path))

jokes_lst = ["The world tongue-twister champion just got arrested. I heard that they're gonna give him a really tough sentence.", " I asked God for a bike, but I know God doesn’t work that way. So I stole a bike and asked for forgiveness.",
"We live in a society where pizza gets to your house before the police.", "Politicians and diapers have one thing in common. They should both be changed regularly, and for the same reason.", "I thought I wanted a career, turns out I just wanted paychecks.", "I tried to change my password to penis but they said it was too short."]

languages = {'Afrikaans': 'af', 'Irish': 'ga', 'Albanian': 'sq', 'Italian': 'it', 'Arabic':'ar', 'Japanese':'ja', 'Azerbaijani': 'az', 'Kannada': 'kn', 'Basque': 'eu', 'Korean': 'ko', 'Bengali':'bn',
'Latin': 'la', 'Belarusian': 'be', 'Latvian': 'lv', 'Bulgarian': 'bg', 'Lithuanian': 'lt', 'Catalan': 'ca', 'Macedonian': 'mk', 'Chinese': 'zh-CN', 'Malay':'ms', 'Maltese':'mt', 'Croatian':'hr', 'Norwegian':'no', 'Czech':'cs',
'Persian': 'fa', 'Danish':'da', 'Polish':'pl', 'Dutch':'nl', 'Portuguese':'pt', 'English':'en', 'Romanian':'ro', 'Esperanto':'eo', 'Russian':'ru', 'Estonian':'et', 'Serbian':'sr', 'Filipino':'tl', 'Slovak':'sk', 'Finnish':'fi',
'Slovenian':'sl', 'French':'fr', 'Spanish':'es', 'Galician':'gl', 'Swahili':'sw', 'Georgian':'ka', 'Swedish':'sv', 'German':'de', 'Tamil':'ta', 'Greek':'el', 'Telugu': 'te', 'Gujarati': 'gu', 'Thai':'th', 'Haitian Creole':'ht', 'Turkish':'tr',
'Hebrew':'iw', 'Ukrainian':'uk', 'Hindi':'hi', 'Urdu':'ur', 'Hungarian':'hu', 'Vietnamese':'vi', 'Icelandic':'is', 'Welsh':'cy', 'Indonesian':'id', 'Yiddish':'yi'}

def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak('Good Morning sir')
    elif hour>= 12 and hour < 18:
        speak('Good Afternoon sir')
    else:
        speak('Good Evening sir')
    speak('I am David, your assistant, please tell me how may I help you')


def takeCommand():
    y = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening...')
        y.pause_threshold = 0.7
        y.phrase_threshold = 1
        #Increase energy_threshold to reduce background noise to more than 300
        audio = y.listen(source)
    try:
        print('Recognizing')
        query = y.recognize_google(audio, language='en-in')
        print(f'User Said: {query}\n')
    except Exception as e:
        # print(e)
        print('Say that again please')
        return 'None'
    return query

def takeCommand1():
    y = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening...')
        y.pause_threshold = 0.7
        y.phrase_threshold = 1
        #Increase energy_threshold to reduce background noise to more than 300
        audio = y.listen(source)
    try:
        print('Recognizing')
        query = y.recognize_google(audio, language='en-in')
        print(f'User Said: {query}\n')
    except Exception as e:
        return 'None'
    return query


def sendEmail(to, subj, msg):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('thedavid090@gmail.com', 'winner@09')
    content = 'Subject: {}\n\n{}'.format(subj, msg)
    server.sendmail('thedavid090@gmail.com', to, content)
    server.close()



while True:
    start = takeCommand1().lower()
    if 'david' in start:
            wishMe()
            while True:
                query = takeCommand().lower()

                if 'who is' in query:
                    speak('Searching wikipedia')

                    query = query.replace('who is', '')

                    results = wikipedia.summary(query, sentences=2) #returns 2 sentences
                    speak('According to wikipedia')
                    print(results)
                    speak(results)

                elif 'what is' in query:
                    speak('Searching for the results')

                    query = query.replace('what is', '')
                    results = wikipedia.summary(query, sentences=2)
                    print(results)
                    speak(results)

                elif 'hi' in query:
                    speak('Hello there, how can I help you')

                elif 'thank you' in query:
                    speak('Anytime for you sir, any other way that I could help you?')

                elif 'open youtube' in query:

                    speak('Do you want to search anything specific')
                    ans = takeCommand().lower()

                    if 'yes' in ans:
                        speak('What would you like to search')
                        searcher = takeCommand().capitalize()
                        lst = searcher.split()
                        webbrowser.get('chrome').open('https://www.youtube.com/results?search_query=' + '+'.join(lst))

                    elif 'no' in ans:
                        webbrowser.get('chrome').open_new('https://youtube.com')
                        speak('Opening Youtube')

                elif 'open google' in query:

                    speak('Do you want to search anything specific')
                    ans = takeCommand().lower()

                    if 'yes' in ans:
                        speak('What would you like to search')
                        searcher = takeCommand().capitalize()
                        lst = searcher.split()
                        webbrowser.get('chrome').open('https://www.google.com/search?q=' + '+'.join(lst))

                    elif 'no' in ans:
                        webbrowser.get('chrome').open('https://google.com')
                        speak('Opening Google')

                elif 'new folder' in query:
                    try:
                        prntdir = 'C:\\Users\\kush\\Desktop'
                        speak('What name would you like to give to the folder')
                        direc = takeCommand().capitalize()
                        path = os.path.join(prntdir, direc)
                        os.mkdir(path)
                        speak(f'Folder with name {direc} has been created')
                    except:
                        speak('File already exists')

                elif 'open mail' in query:
                    speak('Yeah Sure')
                    webbrowser.get('chrome').open('https://mail.google.com/mail/u/2/#inbox')
                    speak('Opening mail')

                elif 'open command prompt' in query:
                    cmd_dir = 'C:\Windows\system32\cmd.exe'
                    os.startfile(cmd_dir)

                elif 'the time' in query:
                    strTime = datetime.datetime.now().strftime('%H:%M:%S')
                    speak(f'the time is {strTime}')

                elif 'date' in query:
                    strDate = datetime.datetime.now().strftime('%a %b %d %Y')
                    speak(f'today is {strDate}')

                elif 'email to my friend' in query:
                    try:
                        speak('What is the subject?')
                        subj = takeCommand()
                        subj = subj.capitalize()

                        speak('What is the message?')
                        msg = takeCommand().capitalize()

                        to = 'kushag09@gmail.com'
                        sendEmail(to, subj, msg)

                        speak('Email has been sent')

                    except Exception as e:
                        speak("Sorry, Couldn't send the email")

                elif 'joke' in query:
                    joke = random.choice(jokes_lst)
                    speak(joke)

                elif 'translate' in query:
                    speak('Yeah Sure')

                    speak('From which language to translate')
                    transLang = takeCommand().capitalize()

                    speak('Say the word or sentence to translate please')
                    trans_word = takeCommand().lower()

                    speak('In which language should I translate')
                    trans_lang = takeCommand().capitalize()

                    translator = Translator()
                    try:
                        lang = languages[trans_lang]
                        lang1 = languages[transLang]
                        translated_word = translator.translate(trans_word, src=lang1, dest=lang)
                        speak(f"{trans_word} in {trans_lang} is {translated_word.pronunciation}")

                    except Exception as e:
                        speak('Language was not found in my dictionary')
                    except:
                        speak('Please speak again')
                        continue

                elif 'reminder' in query:
                    speak("What shall I remind you about?")
                    text = takeCommand().lower()
                    if 'david' in text:
                        text = text.replace('david', 'me')
                    elif 'you' in text:
                        text = text.replace('you', 'me')

                    speak("In how many minutes?")
                    local_time = takeCommand()
                    local_time = local_time.replace('minutes', '')
                    local_time = local_time.replace('minute', '')
                    local_time = local_time.replace('in', '')

                    local_time = float(local_time)
                    local_time = local_time * 60
                    speak('I will remind you and till then you can relax')

                    time.sleep(local_time)
                    speak(f"Sir, please be ready {text}")

                elif 'bye' in query:
                    speak('It was nice spending time with you sir, have a good time')
                    break
    else:
        continue

    '''
    elif 'play music' in query:
        music_dir = ENTER YOUR SONGS PATH
        songs = os.listdir(music_dir)
        os.startfile(os.path.join(music_dir, songs[0]))
    '''
