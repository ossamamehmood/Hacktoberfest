import pytube

print(" SIMPLE YOUTUBE DOWNLOADER \n")

link = input("Enter youtube url: ")
path = input("Enter path to save video, ex. D:\\video: ")

get = pytube.YouTube(link)
filter = get.streams.filter(progressive=True, file_extension='mp4')
filter.get_highest_resolution().download(path)
print("your video was ben downloaded check ->", path)