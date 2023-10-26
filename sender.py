import datetime as dt
import random
import smtplib
name_of_ttxt_file = ''
now = dt.datetime.now()
day = now.weekday()
if day == 0:
    with open(name_of_ttxt_file) as file:
        quotes = file.readlines()
        quote_of_day = random.choice(quotes)

    my_email = ''
    app_password = ''
    with smtplib.SMTP("smtp.gmail.com") as connection:
        connection.starttls()
        connection.login(user=my_email, password=app_password)
        connection.sendmail(from_addr=my_email,to_addrs='youremail.66@gmail.com', msg=f'Subject:Hello\n\n{quote_of_day}')
