import streamlit as st
import speech_recognition as sr

r = sr.Recognizer()
with sr.AudioFile('audio.wav') as source:
    audio = r.record(source)
    try:
        text = r.recognize_google(audio)
        print("You said : {}".format(text))
    except:
        print("Sorry we could not recognize what you said. You can try again.")