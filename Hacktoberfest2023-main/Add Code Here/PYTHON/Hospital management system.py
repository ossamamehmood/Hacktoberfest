from sys import exit
import mysql.connector as sql

conn = sql.connect(host='localhost', user='root', password='scott', database='project3')
if conn.is_connected():
    print()
    print("------------------------------------")
    print("|Successfully Connected To Database|")
    print("------------------------------------")
    print("------------------------------------")
    print("----------Made By Ayushman----------")
    print("------------------------------------")
c1 = conn.cursor()

print("------------------------------------")
print("|         FORTIS HOSPITAL          |")
print("------------------------------------")
print("------------------------------------")
print("|    HOSPITAL MANAGEMENT SYSTEM    |")
print("------------------------------------")
print("------------------------------------")
print('|       "MAY GOD BLESS YOU"        |')
print("------------------------------------")
print("|1.LOGIN|")
print("|2.EXIT |")
choice = int(input("ENTER YOUR CHOICE:"))

if choice == 1:
    u1 = input("enter user name:")
    pwd1 = input("enter the password:")
    while u1 == 'admin' and pwd1 == 'project':
        print("~")
        print("")
        print("Acccess Granted")
        print("")
        print("~")
        print("+----------------------------------+")
        print("|        WELCOME TO HOSPITAL       |")
        print("|----------------------------------|")
        print("| Successfully Connected To Server |")
        print("|----------------------------------|")
        print('|  1.Register New Patient details  |')
        print('|  2.Register New Doctor details   |')
        print('|  3.Register New Worker details   |')
        print("|  4.Total patient info            |")
        print("|  5.Total doctor info             |")
        print("|  6.Total worker info             |")
        print('|  7.Patient Detail                |')
        print('|  8.Doctor Detail                 |')
        print('|  9.Worker Detail                 |')
        print('|  10.Exit                         |')
        print("+----------------------------------+")
    
        choice = int(input('ENTER YOUR CHOICE:'))
        if choice == 1:
                p_name = input('Enter Patient Name:')
                p_age = int(input('Enter Age:'))
                p_problems = input('Enter the Problem/Disease:')
                p_phone = int(input('Enter Phone number:'))
                sql_insert = "insert into patient_details values(""'" + p_name + "'," + str(p_age) + ",'" + p_problems + "'," + str(p_phone) + ")"
                c1.execute(sql_insert)
                print('SUCCESSFULLY REGISTERED')
                conn.commit()
                
        elif choice == 2:
                d_name = input('Enter Doctor Name:')
                d_age = int(input('Enter Age:'))
                d_department = input('Enter the Department:')
                d_phone = int(input('Enter Phone number:'))
                sql_insert = "insert into doctor_details values(""'" + d_name + "'," + str(d_age) + ",'" + d_department + "'," + str(d_phone) + ")"
                c1.execute(sql_insert)
                print('successfully registered')
                conn.commit()
            
        elif choice == 3:
                w_name = input('Enter Worker Name:')
                w_age = int(input('Enter Age:'))
                w_workname = input('Enter type of work:')
                w_phone = int(input('Enter Phone number:'))
                sql_insert = "insert into worker_details values(""'" + w_name + "'," + str(w_age) + ",'" + w_workname + "'," + str(w_phone) + ")"
                c1.execute(sql_insert)
                print('successfully registered')
                conn.commit()
                
        elif choice == 4:
                sql_w = 'select * from patient_details'
                c1.execute(sql_w)
                print("|----------------------------------------------|")
                r = c1.fetchall()
                for i in r:
                    print(i)
                print("|----------------------------------------------|")    
                    
        elif choice == 5:
                sql_x = "select * from doctor_details"
                c1.execute(sql_x)
                print("|------------------------------------------------------|")
                s = c1.fetchall()
                for i in s:
                    print(i)
                print("|------------------------------------------------------|")
    
        elif choice == 6:
                sql_y = "select * from worker_details"
                c1.execute(sql_y)
                print("|--------------------------------------------------|")
                t = c1.fetchall()
                for i in t:
                    print(i)
                print("|--------------------------------------------------|")
                
        elif choice == 7:
                h = input("Enter the name:")
                sql_w = 'select * from patient_details where p_name=("{}")'.format(h)
                c1.execute(sql_w)
                print("|----------------------------------------------|")
                u = c1.fetchall()
                for i in u:
                    print(i)
                print("|----------------------------------------------|")
    
        elif choice == 8:
                d = input("Enter the name:")
                sql_d = 'select * from doctor_details where d_name=("{}")'.format(d)
                c1.execute(sql_d)
                print("|------------------------------------------------------|")
                v = c1.fetchall()
                for i in v:
                    print(i)
                print("|------------------------------------------------------|")
    
        elif choice == 9:
                f = input("Enter the name:")
                sql_f = 'select * from worker_details where w_name=("{}")'.format(f)
                c1.execute(sql_f)
                print("|------------------------------------------------|")
                w = c1.fetchall()
                for i in w:
                    print(i)
                print("|------------------------------------------------|")
    
        elif choice == 10:
                exit()
        
    else:
        print('Wrong Username or Password')

if choice == 2:
    exit()