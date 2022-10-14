#BLOOD BANK MANAGEMENT SYSTEM

import time
import pickle
from datetime import date
import random

o=0
while True:
    while o==0:
        print("="*140)
        print("""Welcome to the Blood Bank Management System, What would you like to do?
    1.Donate Blood
    2.Request for blood
    3.Display all the Blood donated
    4.Important Contacts
    5.Blood Compatibility Chart
    6. Exit""")
        
        choice=int(input('\t--------->'))
        if choice==1:
            print("="*140)
            Name=str(input('Enter your name: '))
            Phno=input('Enter your phone number: ')
            if len(Phno)==10:
                pass
            
            else:
                print("please enter a valid phone number")
                break
            
            Disease=str(input("If you've had any bloodborne diseases ie.- Diabetes , HIV etc or if you have had a tattoo in the past 6 months, Please enter 'Y': "))
            if Disease in 'Yy':
                print("You are not eligible to donate blood! Thank you for the kind thoughts!")
                break
            
            else:
                Age=int(input('Enter your age: '))
                if Age<16:
                    print("You have to be over the age of 16 to donate blood! Please come back when you are eligible")
                    break
                
                else:
                    Weight=float(input('Please enter your weight: '))
                    if Weight<=50:
                        print("You are underweight! Please try to donate later when you are eligible")
                        break
                    else:

                        print("="*140)
                        Btype=int(input("""\tEnter your blood type from the following:
                            1.O+\t3.A+\t5.B+\t7.AB+
                            2.O-\t4.A-\t6.B-\t8.AB-
                            \t\t--------->"""))
                        
                        if Btype==1:
                            blood='O+'
                            
                        elif Btype==2:
                            blood='O-'
                            
                        elif Btype==3:
                            blood='A+'
                            
                        elif Btype==4:
                            blood='A-'
                            
                        elif Btype==5:
                            blood='B+'
                            
                        elif Btype==6:
                            blood='B-'
                            
                        elif Btype==7:
                            blood='AB+'
                            
                        elif Btype==8:
                            blood='AB-'
                            
                        else:
                            print('That is not a valid value,Please try again!')

            print("="*140)
            Mode=int(input("""Would you like to donate blood to our mobile unit or donate in times of emergency upon recieving a call?
            1) To donate blood to our mobile unit
            2) To donate blood by recieving a call
            \t\t\t---------->  """))
            print("="*140)
            
            if Mode==1:
                print("""
                Our mobile unit will contact you to set an appointment.
                For any queries please contact our mobile unit on-
                \t\t052 896 9400 (Sharjah)
                \t\t056 358 9743 (Dubai)
                \t\t052 349 8000 (Ajman)
                """)
                
                Mode='Mobile unit'

            elif Mode==2:
                print("""
                You will be contacted upon need of individuals
                Please be attentive to your calls and save the numbers of our hotlines.
                \t\t052 896 9400 (Sharjah)
                \t\t056 358 9743 (Dubai)
                \t\t052 349 8000 (Ajman)
                """)

                Mode='On call'

            else:
                print('you have entered an invalid value')
                break

        
            Date=str(date.today())
            try:
                PreviousData=open("Blood Bank","rb+")
                Records=pickle.load(PreviousData)

                j=0
                for i in Records:                                                           
                    j+=1                        

                Newcode=random.randint(1000,9999)
                    
                for k in range(j):
                    for code in Records:
                        if code[5]==Newcode:                                       
                            Newcode=random.randint(1000,9999)
                            
                Data=[[Name,blood,Date,Phno,Mode,Newcode]]
                        
                Records+=Data
                PreviousData.truncate(0)
                PreviousData.close()
                UpdatedData=open("Blood Bank","wb")
                pickle.dump(Records,UpdatedData)
                UpdatedData.close()

            except FileNotFoundError:
                NewFile=open("Blood Bank","wb")
                Record=[[Name,blood,Date,Phno,Mode,(random.randint(1000,9999))]]
                pickle.dump(Record,NewFile)
                NewFile.close()
                
            randomfact=random.randint(0,2)
            
            if randomfact==0:
                print("Donating your blood has helped regulate good health and reduced the risk of cancer and hemochromotosis and may have helped save a life!")
                
            elif randomfact==1:
                print("Donating blood has helped in reducing the risk of damage to your liver and pancreas! and may have helped save a  life!")
                
            else:
                print("Donating blood may have helped in improving your cardiovascular health and reducing obesity and may have helped save a life!")
                
        elif choice==2:
            while True:
                print("="*140)
                print("""1) To recieve blood from a person or mobile unit
2) To check availability of all blood you can receive
3) To check availability of a particular blood group
4) To check compatibility of your blood group
5)To go back to main Menu""")
                
                x=int(input("\t---------> "))
                Breaker=0
                if x==1:
                    print("="*140)
                    try:
                        BloodData=open("Blood Bank","rb")
                        Data=pickle.load(BloodData)
                        BloodData.close()
                        Heading=1
                        for i in Data:
                            
                            if Heading==1:
                                Heading=0
                                print("Blood Bag Code\t\tName\t\tBlood Group\tDate\t\t\tPhone number\t\tMethod of receival")
                                print(i[5],"\t\t\t",i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                
                            else:
                                print(i[5],"\t\t\t",i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])

                        print("="*125)
                                
                        if Heading==1:
                            print("There is no blood available in the blood bank")

                        if Heading==0:
                            Newdata=[]
                            Bcode=int(input("Enter the code of the blood you want to acquire: "))
                            Exists=0
                            for i in Data:
                                if i[5]==Bcode:
                                    Exists=1
                                    
                                    if (i[4]).lower()=="on call":
                                        print("You can contact the donor through the number -",i[3])

                                    else:
                                        print("You can acquire the blood from the mobile unit! Please go back to previous menu for contact details of the mobile units.")

                                else:
                                    Newdata.append(i)

                            if Exists==0:
                                print("You have entered an invalid code. Please try again!")

                            else:
                                PreviousData=open("Blood Bank","wb")
                                PreviousData.truncate(0)
                                PreviousData.close()
                                UpdatedData=open("Blood Bank","wb")
                                pickle.dump(Newdata,UpdatedData)
                                UpdatedData.close()
                                break

                    except FileNotFoundError:
                        print("There is no file to print!")

                    except TypeError:
                        continue


                elif x==2:
                    
                    try:
                        BloodData=open("Blood Bank","rb")
                        Data=pickle.load(BloodData)
                        BloodData.close()
                        
                        print("""\tPick a mode of receiving the blood:
\t1. To recieve blood directly from a person (only in emergency)
\t2. If you would like to recieve blood which was recieved from a user before, tested and stored in our mobile unit""")
                        
                        i=int(input('\t\t---------> '))

                        if i==1:
                            Btype=int(input("""\t\tEnter your blood type from the following:
                            1.O+\t3.A+\t5.B+\t7.AB+
                            2.O-\t4.A-\t6.B-\t8.AB-
                            \t\t--------->"""))
                            
                            if Btype==1:
                                blood=['O+',"O-"]
                                
                            elif Btype==2:
                                blood=['O-']
                                
                            elif Btype==3:
                                blood=['A+','A-','O+','O-']
                                
                            elif Btype==4:
                                blood=['A-','O-']
                                
                            elif Btype==5:
                                blood=['B+','B-','O+','O-']
                                
                            elif Btype==6:
                                blood=['B-','O-']
                                
                            elif Btype==7:
                                blood=['AB+','AB-','O+','O-','A+','A-','B+','B-']
                                
                            elif Btype==8:
                                blood=['AB-','O-','A-','B-']
                                
                            else:
                                print('That is not a valid value,Please try again!')

                            NoMatch=1
                            heading=1
                            for i in Data:
                                if i[4]=="On call":
                                    for j in blood:                                   
                                        if i[1]==j:
                                            
                                            if NoMatch==1:
                                                NoMatch=0
                                                print("="*125)
                                                
                                            if heading==1:
                                                heading=0
                                                print("Name\t\tBlood Group\tDate\t\t\tPhone number\t\tMode of receiving")
                                                print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                                
                                            else:
                                                print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                        
                            if NoMatch==1:
                                print("="*125)
                                print("There is no match of blood group")
                                
                        if i==2:
                            
                            Btype=int(input("""\t\tEnter your blood type from the following:
                            1.O+\t3.A+\t5.B+\t7.AB+
                            2.O-\t4.A-\t6.B-\t8.AB-
                            \t\t--------->"""))
                            
                            if Btype==1:
                                blood=['O+',"O-"]
                                
                            elif Btype==2:
                                blood=['O-']
                                
                            elif Btype==3:
                                blood=['A+','A-','O+','O-']
                                
                            elif Btype==4:
                                blood=['A-','O-']
                                
                            elif Btype==5:
                                blood=['B+','B-','O+','O-']
                                
                            elif Btype==6:
                                blood=['B-','O-']
                                
                            elif Btype==7:
                                blood=['AB+','AB-','O+','O-','A+','A-','B+','B-']
                                
                            elif Btype==8:
                                blood=['AB-','O-','A-','B-']
                                
                            else:
                                print('That is not a valid value,Please try again!')
                            NoMatch=1
                            heading=1
                            
                            for i in Data:
                                if i[4]=="Mobile unit":
                                    for j in blood:                                   
                                        if i[1]==j:
                                            
                                            if NoMatch==1:
                                                NoMatch=0
                                                print("="*140)
                                                
                                            if heading==1:
                                                heading=0
                                                print("Name\t\tBlood Group\tDate\t\t\tPhone number\t\tMode of receiving")
                                                print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                                
                                            else:
                                                print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                        
                            if NoMatch==1:
                                print("="*140)
                                print("There is no match of blood group")
                                
                    except FileNotFoundError:
                        print("="*140)
                        print("There is no data in the file to print!")

                    except TypeError:
                        continue
                    
                elif x==3:
                    try:
                        BloodData=open("Blood Bank","rb")
                        Data=pickle.load(BloodData)
                        BloodData.close()
                        
                        Btype=int(input("""\tEnter your blood type from the following:
                            1.O+\t3.A+\t5.B+\t7.AB+
                            2.O-\t4.A-\t6.B-\t8.AB-
                            \t\t--------->"""))
                        print("="*140)
                        
                        if Btype==1:
                            blood='O+'
                            
                        elif Btype==2:
                            blood='O-'
                            
                        elif Btype==3:
                            blood='A+'
                            
                        elif Btype==4:
                            blood='A-'
                            
                        elif Btype==5:
                            blood='B+'
                            
                        elif Btype==6:
                            blood='B-'
                            
                        elif Btype==7:
                            blood='AB+'
                            
                        elif Btype==8:
                            blood='AB-'
                            
                        else:
                            print('That is not a valid value,Please try again!')
                        NoMatch=1
                        print("Name\t\tBlood Group\tDate\t\t\tPhone number\t\tMethod of receiving")
                        for i in Data:
                            if i[1]==blood:
                                    NoMatch=0
                                    print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                                    
                        if NoMatch==1:
                            print("There is no match of blood group")
                    
                    except FileNotFoundError:
                        print("="*140)
                        print("There is no data in the file to print!")
                    
                    
                elif x==4:
                    btype=int(input("""\tEnter your blood type from the following:
                            1.O+\t3.A+\t5.B+\t7.AB+
                            2.O-\t4.A-\t6.B-\t8.AB-
                            \t\t--------->"""))
                    print("="*140)
                    
                    if btype==1:
                        print("You can receive the blood types O+ and O-")
                        
                    elif btype==2:
                        print("You can receive the blood type O-")
                        
                    elif btype==3:
                        print("You can receive the blood types A+,A-,O+ and O-")
                        
                    elif btype==4:
                        print("You can receive the blood types A- and O-")
                        
                    elif btype==5:
                        print("You can receive the blood types B+,B-,O+ and O-")
                        
                    elif btype==6:
                        print("You can receive the blood types B- and O-")
                        
                    elif btype==7:
                        print("You can receive all blood types!")
                        
                    elif btype==8:
                        print("You can receive the blood types A-,B-,AB- and O-")
                        
                    else:
                        print("You have entered an invalid value")
                            
                elif x==5:
                    print("Going back to main menu!")
                    time.sleep(3)
                    print("Welcome back to the main menu!")
                    break

                else:
                    print("You have entered an invalid option! , Please try again.")

        elif choice==3:
            print("="*140)
            try:
                BloodData=open("Blood Bank","rb")
                Data=pickle.load(BloodData)
                BloodData.close()
                Heading=1
                for i in Data:
                    if Heading==1:
                        Heading=0
                        print("Name\t\tBlood Group\tDate\t\t\tPhone number\t\tMethod of recieval")
                        print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                        
                    else:
                        print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4])
                        
                if Heading==1:
                    print("There is no blood available in the blood bank")
                
            except FileNotFoundError:
                print("There is no file to print!")

            except TypeError:
                continue

        elif choice==4:
            print("="*140)
            print("""\t            HOSPITALS TO DONATE BLOOD

\t\tLatifa hospital:04 219 3000
\t\tKuwait hospital:06 524 2111
\t\tZulekha hospital:600524442
\t\tAl Zahra hospital:06 561 9999

\tYou can also donate blood through our mobile blood donation unit:-
\t\tMobile: 052 896 9400 (Sharjah)
\t\t056 358 9743 (Dubai)
\t\t052 349 8000 (Ajman)""")

        elif choice==5:
            print("="*140)
            print("""BLOOD GROUPS\t\t\t\tDONORS\t\t\t\t
\t\t\tO-\tO+\tB-\tB+\tA-\tA+\tAB-\tAB+
\t\tAB+\t✓\t✓\t✓\t✓\t✓\t✓\t✓\t✓
\t\tAB-\t✓\t\t✓\t\t✓\t\t✓\t
\t\tA+\t✓\t✓\t\t\t✓\t✓
RECEIVERS\tA-\t✓\t\t\t\t✓
\t\tB+\t✓\t✓\t✓\t✓
\t\tB-\t✓\t\t✓
\t\tO+\t✓\t✓
\t\tO-\t✓""")

        elif choice==6:
            print("="*140)
            print("Thank you for your time!")
            print("="*140)
            print("Exiting in 3")
            time.sleep(1)
            print("Exiting in 2")
            time.sleep(1)
            print("Exiting in 1")
            time.sleep(1)
            print("="*140)
            exit()
            
        else:
           print("You have entered an invalid option! , Please try again")

        
        
