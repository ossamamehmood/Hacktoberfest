from tkinter import *

import phonenumbers

from phonenumbers import geocoder

from phonenumbers import carrier


#to create the window

root=Tk()

root.title("Phone Number Location Tracker")

root.geometry("600x300")


#to create the label

label1=Label(root,text='Enter the phone number along with country code:',fg='purple',font=('Arial',12))

label1.grid(row=0,column=0,padx=5,pady=15)


#to store the entered phone number

number=StringVar()


#creating text box to accept the phone number

tbox1=Entry(root,textvariable=number,fg='black',font=('Arial',12))

tbox1.grid(row=0,column=1)


#function to track the location and the service provider

def phone():

      import phonenumbers
from phonenumbers import geocoder
number=input("Enter a phone number along with country code: ")
location=phonenumbers.parse(number,"CH")
print(geocoder.country_name_for_number(location,"en"))
from phonenumbers import carrier
service_provider=phonenumbers.parse(number,"RO")
print(carrier.name_for_number(service_provider,"en"))



#creating the button

button1=Button(root,command=phone,text='Submit',fg='white',bg='red',font=('Arial bold',12))

button1.grid(row=1,column=1)


#creating an empty label to display the location 

emptylabel1=Label(root,fg='purple',font=('Arial',12))

emptylabel1.grid(row=2,column=1,pady=15)


#creating an empty label to display the service provider

emptylabel2=Label(root,fg='purple',font=('Arial',12))

emptylabel2.grid(row=3,column=1,pady=5)


root.mainloop()