from pytube import YouTube
link=input("Enter Url: ")
video = YouTube(link)
print("\n*******************TITLE**********************")
print(video.title)

print("\n*******************Thumbnail image**********************")
print(video.thumbnail_url)

print(video.streams.all)

stream1=video.streams.first()
stream1.download()

