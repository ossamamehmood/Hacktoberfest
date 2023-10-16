import cv2
import numpy as np
import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk
from src.utils import Park_classifier
from src.utils import Coordinate_denoter

# Initialize the Park_classifier and Coordinate_denoter
classifier = Park_classifier("data/source/CarParkPos")
coordinate_denoter = Coordinate_denoter()

# Create Tkinter application window
root = tk.Tk()
root.title("Parking Space Classifier")

# Function to open a video file
def open_file():
    file_path = filedialog.askopenfilename()
    if file_path:
        process_video(file_path)

# Function to process the video and display in the Tkinter window
def process_video(video_path):
    cap = cv2.VideoCapture(video_path)
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        processed_frame = classifier.implement_process(frame)
        classified_frame = classifier.classify(frame, processed_frame)
        
        # Display the processed video in the Tkinter window
        img = cv2.cvtColor(classified_frame, cv2.COLOR_BGR2RGB)
        img = Image.fromarray(img)
        img = ImageTk.PhotoImage(image=img)

        panel.config(image=img)
        panel.image = img
        panel.update_idletasks()
        
        # Exit condition
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the video capture and close the window when done
    cap.release()
    cv2.destroyAllWindows()

# Button to open a video file
open_button = tk.Button(root, text="Open Video", command=open_file)
open_button.pack(pady=20)

# Panel to display processed video
panel = tk.Label(root)
panel.pack()

# Start the Tkinter main loop
root.mainloop()
