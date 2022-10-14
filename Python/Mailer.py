import smtplib as smtp

print("\n")

name = str(input("Please input your name: "))
sender = str(input("Please input your email address: "))
recipient = str(input("Please input the recipient's email address: "))
subject = str(input("Please input the email's subject: "))
message = str(input("Please input your message: "))


message = """From: From """ + name + """<""" + sender + """>
To: To """ + """<""" + sender + """>
Subject: """ + subject + """
""" + message

print("\n Please wait...")
try:
	#configure smtp settings here
   server = smtp.SMTP('localhost')
   server.sendmail(sender, receiver, message)         
   print ("\n Successfully sent your email")
except SMTPException:
   print ("Error: unable to send email, check your smtp settings")
