# f = open("KrishDiet.txt","w")
# f.write("Hi Krish here is your diet")
# f.close()
# f = open("Krishexercise.txt","w")
# f.write("Hi Krish here is your exercise")
# f.close()
#
# f = open("SamirDiet.txt","w")
# f.write("Hi Samir here is your diet")
# f.close()
# f = open("Samirexercise.txt","w")
# f.write("Hi Samir here is your exercise")
# f.close()
#
# f = open("HarryDiet.txt","w")
# f.write("Hi harry here is your diet")
# f.close()
# f = open("Harryexercise.txt","w")
# f.write("Hi Harry here is your exercise")
# f.close()

def getdate():
    import datetime
    return datetime.datetime.now()


print("What do you want to add press 1 for exercise or press 2 for diet")
inp=int(input())



if inp==1:
    print("what is your name")
    inpname=input()
    if inpname=="Krish":
        print("What do you want to do add or read")
        inpdo=input()

        if inpdo=="add":
            print("Now you can add")
            d= open("Krishexercise.txt","a")
            d.write(input("\n"))
            print("successfully written")
        elif inpdo=="read":

            e=open("Krishexercise.txt")
            print(e.read())
            e.close()

    if inpname=="Samir":
        print("What do you want to do add or read")
        inpdo = input()

        if inpdo == "add":
            print("Now you can add")
            f = open("Samirexercise.txt","a")
            f.write(input())
            print("successfullywritten")

        elif inpdo == "read":

            g = open("Samirexercise.txt")
            print(g.read())
            g.close()


    if inpname=="Harry":
        print("What do you want to do add or read")
        inpdo = input()

        if inpdo == "add":
            print("Now you can add")
            h = open("Harryexercise.txt","a")
            h.write(input())
            print("successfully written")






        elif inpdo == "read":

            i = open("Harryexercise.txt")
            print(i.read())
            i.close()

elif inp==2:
    print("what is your name")
    inpname=input()
    if inpname=="Krish":
        print("What do you want to do add or read")
        inpdo=input()

        if inpdo=="add":
            print("Now you can add")
            j= open("KrishDiet.txt","a")
            j.write(input())
            print("successfully written")
        elif inpdo == "read":

            h = open("KrishDiet.txt")
            print(h.read())
            h.close()

    if inpname=="Samir":
        print("What do you want to do add or read")
        inpdo = input()

        if inpdo == "add":
            print("Now you can add")
            i = open("SamirDiet.txt","a")
            i.write(input())
            print("successfully written")
        elif inpdo == "read":

            j = open("SamirDiet.txt.txt")
            print(j.read())
            j.close()

    if inpname=="Harry":
        print("What do you want to do add or read")
        inpdo = input()

        if inpdo == "add":
            print("Now you can add")
            k = open("HarryDiet.txt","a")
            k.write(input())
            print("successfully written")
        elif inpdo == "read":

            l = open("HarryDiet.txt")
            print(l.read())
            l.close()
else:
    print("Error")
    print("please try again")
