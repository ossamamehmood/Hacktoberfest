print('This program is only for .com websites')
webUrl = input("Enter your website link: ").strip()
if "https://www" in webUrl:
    getUrl = webUrl[webUrl.index("ww") + 4:webUrl.index(".com")]
    print("The url belongs to: " + getUrl)
elif "https://" in webUrl and ".com" in webUrl:
    getUrl = webUrl[8:webUrl.index(".com")]
    print("The url belongs to: " + getUrl)
elif "http://" in webUrl and ".com" in webUrl:
    getUrl = webUrl[5:webUrl.index(".com")]
    print("The url belongs to: " + getUrl)
elif "https://en." in webUrl:
    getUrl = webUrl[11:webUrl.index(".org")]
    print("The url belongs to: " + getUrl)
else:
    print("There are some exceptions please check the url on internet")
