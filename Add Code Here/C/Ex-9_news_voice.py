import requests
import json
def speaking_news(string):
    from win32com.client import Dispatch
    speak = Dispatch("SAPI.SpVoice")
    speak.speak(string)
if __name__ == "__main__":
    speaking_news("let's start todays news")
    url = "https://newsapi.org/v2/top-headlines?country=us&apiKey=bd0f9ac8871c4c798cc503883fdbbfd3"
    news = requests.get(url).text
    new_py = json.loads(news)
    #print(new_py["articles"])
    art = new_py["articles"]
    for article in art:
        for num, article in enumerate(art):
            speaking_news(article['title'])
            print(num ,article["description"], "\n")
            speaking_news("for more details click the given link")
            print(article["url"], "\n")
        
