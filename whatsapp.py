# pip install pywhatkit
import pywhatkit as kit

# Specify the phone number (with country code) and the message. E.g, +919876543210
phone_number = input("Mobile Number with country code : ")
message = input("Message : ")

# Send the message instantly
kit.sendwhatmsg_instantly(phone_number, message)
