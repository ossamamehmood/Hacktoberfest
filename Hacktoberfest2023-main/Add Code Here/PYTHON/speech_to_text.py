import speech_recognition as sr
audio_file = ("sample.wav")
r = sr.Recognizer()
with sr.AudioFile(audio_file) as source:
    audio = r.record(source)

try:
    print("The file contains:",r.recognize_google(audio))
except sr.UnknownValueError:
    print("Google doesnt understand!")