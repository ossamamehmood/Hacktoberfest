# url shortener
import gradio as gr
import pyshorteners

#creating a function to shorten the url
def shorten_url(url):
    shortener = pyshorteners.Shortener()
    short_url = shortener.tinyurl.short(url)
    return short_url

#call the function
def url_shortener(url):
    short_url = shorten_url(url)
    return short_url

iface = gr.Interface(fn=url_shortener, inputs="text", outputs="text", title="URL Shortener")
iface.launch(share=True)