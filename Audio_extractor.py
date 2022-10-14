#!/usr/bin/env python
"""
install pip package: moviepy using the command:
pip install moviepy
"""
import moviepy      # moviepy - Get this library installed in your system [pip install moviepy].
import moviepy.editor
from tkinter import *  # import Tkinter module
from tkinter.filedialog import askopenfilename ,asksaveasfilename  # file dialog to get video and audio file paths.


class Mp3extractor:
    def __init__(self, root):
        self.main = root
        self.main_frame = Frame(root, height=20, width=80)
        self.main_frame.pack(side=TOP, fill=BOTH, padx=10, pady=10)
        self.second_frame = Frame(self.main, width=100)
        self.second_frame.pack(side=BOTTOM, fill=BOTH, padx=10)
        self.open_file_path = StringVar()
        self.save_file_path = StringVar()
        self.content()

    def content(self):
        Label(self.main_frame, text="Enter the path of the video file to be extracted:").pack(side=TOP, anchor='w')
        self.open_path = Entry(self.main_frame, width=50)  # Entry for video file path.
        self.open_path.pack(side=TOP, fill=BOTH)
        Button(self.main_frame, text="Browse..", bg="sky Blue", command=self.fileopen).pack(side=TOP,
                                                                                            anchor='e')  # Button to locate video file.
        Label(self.main_frame, height=3).pack(side=TOP, fill=BOTH)  # Empty Label for good look.
        Label(self.main_frame, text="Enter the path for the converted audio file to be saved:", height=1).pack(side=TOP,
                                                                                                               anchor='w')
        self.save_path = Entry(self.main_frame, width=50)  # Entry for audio file path.
        self.save_path.pack(side=TOP, fill=BOTH)
        Button(self.main_frame, text="Browse..", bg="sky Blue", command=self.filesave).pack(side=TOP,
                                                                                            anchor='e')  # Button to locate audio file to be saved.
        empty_space2 = Label(self.main, text="_" * 60, height=3, fg="red")
        empty_space2.pack(side=TOP, fill=BOTH, anchor='s')
        convert_button = Button(self.second_frame, text="convert", bg="pink", borderwidth=4,
                                command=lambda: [self.file_convert(self.open_file_path, self.save_file_path)])
        convert_button.pack(side=RIGHT, anchor='ne', padx=5, pady=5)  # The convert Button.0

    def fileopen(self):
        self.open_file_path = askopenfilename(
            filetypes=[("All Files", "*.*")]  # Here you can specify different file extensions.
        )
        if not self.open_file_path:
            return
        self.open_path.insert(0, self.open_file_path)  # insert the file path to Entry.

    # to get file path for audio file to be saved.
    def filesave(self):
        self.save_file_path = (asksaveasfilename(
            filetypes=[("audio file", '*.MP3'), ("All files", '*.*')]  # Here you can specify different file extensions.
        ))
        if not self.save_file_path:
            return
        self.save_path.insert(0, self.save_file_path + ".mp3")  # insert the file path to Entry.

    # The main program to convert a video file to audio file.
    def file_convert(self, video_file, audio_file):  # Here video_file and audio_file are the file paths.
        video = moviepy.editor.VideoFileClip(video_file)
        audio = video.audio  # Main convertion from video to audio.
        audio.write_audiofile(audio_file)
        popup = Toplevel()  # A popup window saying completed.
        popup.title("completed!")
        Label(popup, text="sucessfully converted and saved to your location \n\n\n", height=10).pack(side=TOP,
                                                                                                     anchor='nw')
        popup.mainloop()


if __name__ == "__main__":
    uiwindow = Tk()
    uiwindow.title("Audio extractor from Video")
    uiwindow.resizable(False, False)
    obj = Mp3extractor(uiwindow)
    uiwindow.mainloop()