# YouTanion - Pronounced as 'yoo-taa-nyn' - https://github.com/iamsubingyawali/youtanion
# v1.1 A simple CLI based interactive YouTube videos and playlist downloader using pytube
# Developed by Subin Gyawali

# Note: This program was solely made for educational purposes and must not be
# used to download content without the permission of the copyright owner. This program must not be used in any other
# way that violates YouTube's terms of service.

# Install requirements
# pip install pytube
# pip install validators
# pip install requests

# importing required libraries
import pathlib
import os
import requests
import validators
from pytube import Playlist
from pytube import YouTube
from pytube.helpers import safe_filename

# Main function to execute when program starts
def main():
    # Allowing user to select between a audio/video and a playlist
    down_type = input("1. Download Audio/Video\n2. Download Playlist\n\nChoose an option: ")
    if down_type == '1':
        video_interaction()
    elif down_type == '2':
        playlist_interaction()
    else:
        print("\nInvalid option.\n")
        main()


# function to execute when user wishes to download a video
def video_interaction():
    video_link = input("\nPaste the video link: ")
    # checking if the input url is valid
    if check_url(video_link):
        try:
            video = YouTube(video_link)
            # allowing user to choose between video and audio only
            video_type = input("\n1. Download Video\n2. Download Audio Only\n\nChoose an option: ")

            # VIDEO DOWNLOAD
            if video_type == '1':
                print("\nFetching available resolutions. Please wait...\n")
                # defining a list to store the video streams
                video_streams = []
                count = 1
                # using loops to display all the videos with av1 video codecs
                # with different resolutions
                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.16M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.12M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.08M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.05M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.04M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.01M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                for i in video.streams.filter(mime_type="video/mp4", video_codec="av01.0.00M.08"):
                    print(str(count) + ".", i.resolution)
                    count += 1
                    video_streams.append(i)

                # allowing users to choose a resolution to download
                video_res = input("\nChoose a video resolution: ")
                try:
                    if count > int(video_res) > 0:
                        # creating a download directory
                        directory = "Downloads/Videos"
                        directory = os.path.join(pathlib.Path(__file__).parent.absolute(), directory)
                        os.makedirs(directory, exist_ok=True)
                        # starting the video download
                        print("\nDownloading video. Please wait...")
                        if video_streams[int(video_res) - 1].download(directory):
                            print("\nSuccessfully downloaded.")
                            end_note()
                    else:
                        print("\nInvalid option.")
                        video_interaction()
                # handling value error exceptions
                except ValueError:
                    print("\nInvalid option.")
                    video_interaction()

            # AUDIO DOWNLOAD
            elif video_type == '2':
                # creating a download directory
                directory = "Downloads/Audios"
                directory = os.path.join(pathlib.Path(__file__).parent.absolute(), directory)
                os.makedirs(directory, exist_ok=True)
                # starting the audio download
                print("\nDownloading and converting audio. Please wait...")
                stream = video.streams.filter(mime_type="audio/mp4", only_audio=True).first()
                if stream.download(directory):
                    try:
                        input_path = os.path.join(pathlib.Path(__file__).parent.absolute(),
                                                  ("Downloads/Audios/" + safe_filename(stream.title) + ".mp4"))
                        input_path = pathlib.Path(input_path)
                        input_path.rename(input_path.with_suffix('.m4a'))
                        print("\nSuccessfully downloaded.")
                        end_note()
                    except Exception:
                        print("\nSuccessfully downloaded. Conversion attempt failed.\n")
                        end_note()
            else:
                print("\nInvalid option.")
                video_interaction()
        # handling pytube exceptions
        except Exception:
            print("\nInvalid video URL.")
            video_interaction()
    else:
        print("\nInvalid video URL.")
        video_interaction()


# function to execute when user wishes to download a playlist
def playlist_interaction():
    list_link = input("\nPaste the YouTube public playlist link: ")
    # checking if the input url is valid
    if check_url(list_link):
        try:
            playlist = Playlist(list_link)
            # allowing user to choose between video and audio only
            video_type = input("\n1. Download Videos\n2. Download Audios Only\n\nChoose an option: ")

            # VIDEO DOWNLOAD
            if video_type == '1':
                # creating a download directory
                directory = "Downloads/Videos"
                directory = os.path.join(pathlib.Path(__file__).parent.absolute(), directory)
                os.makedirs(directory, exist_ok=True)
                # downloading playlist videos in highest quality
                print("\nDownloading started. Please wait...\n")
                for video in playlist.videos:
                    if (os.path.isfile("Downloads/Videos/"+safe_filename(video.title)+".mp4")):
                        print(f"Skipping > {video.title}")
                        continue
                    else:
                        print(f"Downloading > {video.title}")
                        video.streams.get_highest_resolution().download(directory)
                print("\nSuccessfully downloaded the playlist.\n")
                end_note()

            # AUDIO DOWNLOAD
            elif video_type == '2':
                # creating a download directory
                directory = "Downloads/Audios"
                directory = os.path.join(pathlib.Path(__file__).parent.absolute(), directory)
                os.makedirs(directory, exist_ok=True)
                print("\nDownloading started. Please wait...\n")
                # downloading playlist audios
                for video in playlist.videos:
                    if (os.path.isfile("Downloads/Audios/"+safe_filename(video.title)+".m4a")):
                        print(f"Skipping > {video.title}")
                        continue
                    else:
                        print(f"Downloading and Converting > {video.title}")
                        video.streams.filter(mime_type="audio/mp4", only_audio=True).first().download(directory)
                        try:
                            input_path = os.path.join(pathlib.Path(__file__).parent.absolute(),
                                                    ("Downloads/Audios/" + safe_filename(video.title) + ".mp4"))
                            input_path = pathlib.Path(input_path)
                            input_path.rename(input_path.with_suffix('.m4a'))
                        except Exception:
                            continue
                print("\nSuccessfully downloaded the playlist.\n")
                end_note()
            else:
                print("\nInvalid option.")
                playlist_interaction()

        except Exception:
            print("\nInvalid playlist URL.")
            playlist_interaction()
    else:
        print("\nInvalid playlist URL.")
        playlist_interaction()


# function to check the validity and reachability of the given URL
def check_url(url):
    # checking URL format
    if validators.url(url):
        try:
            # checking availability
            req = requests.get(url, stream=True)
            if req.status_code == 200:
                return True
            else:
                return False
        except Exception:
            return False
    else:
        return False


# function to show an end message after each successful operation
def end_note():
    print("\nYouTanion. Made with ❤ and Python.\n")
    main()


# start of the program
print("\nYouTanion - An interactive YouTube videos downloader - by Subin\n")
main()