
#<----------Choice based Adventure Game---------------->

name=input("Register yourself by entering Your Name: ")


print("\n\t\t\t\t\t\t\tWelcome Aboard!",name,"\n")
print("\t\t\t\t\t\t   You are now part of the game\n")
print("Note:- Before Proceeding, be aware of the Game Rules. Make choices throughout the game based on the situation.\n")
print("---------------------------------------------------------------------------------------------------------------------------------------------\n")

ch=input("You are lost in the Middle of the woods. You got seperated from rest of your Camp members. After walking miles, you find the Map of your Base Camp and also find footprints of your camp members.\n\nType 'footprint' to follow the traces of the prints or Type 'map' to follow the direction towards the camp base: ")

if  ch == "footprint" :
    
    print("\nYou decide to follow the footprints along the way, finds it to be vanishing at some point and end up somewhere deeper in the woods.")
    print("\nSorry! You didn't make it to the end. Try again!\n")

elif ch == "map" :
    
    ch=input("\nYou decide to depend on Map and follow the direction of your Base Camp. After reading the map for some hours you reach to the shore of the River. You have to cross the river to reach to other side of the land. To cross the river there are only two ways one is to use the weak bridge or jump upon the submerged rocks.\n\nType 'bridge' to use the old wooden bridge or Type 'stone' to jump over the submerged rocks: ")

    if ch == "bridge" :

        print("\nYou tried to cross the river through bridge but fell off in the river as the bridge got broken due to its weak structure.")
        print("\nSorry! You didn't make it to the end. Try again!\n")

    elif ch == "stone" :

        ch=input("\nYou tried to cross the river through submerged stones and you made it to the other side of the land. You followed the map and reached the site where one path leads to Dense Jungle and other path to the Hill.\n\nType 'deepjungle' to walkthrough dense jungle or Type 'hill' to climp up the way to hill: ")

        if ch == "deepjungle" :

            print("\nYou decided to move into dense jungle. Presence of many dangerous wild animals, made you panicked, and you are fainted.")
            print("\nSorry! You didn't make it to the end. Try again!\n")

        elif ch == "hill" :

            ch=input("\nYou decided to climp up the hill. You made it to the top of the hill. You are Hungry!. You found some berries on Tree.\n\nType 'eat' to fulfill your hunger or Type 'throw' to throw away the berries: ")

            if ch == "eat" :

                print("\nYou ate the berries and were effected by its poisonous nature. You Died!")
                print("\nSorry! You didn't make it to the end. Try again!\n")

            elif ch == "throw" :

                ch=input("\nYou threw away the berries from your hand and continued your journey. You followed the map and reached your Base Camp, but found nobody at the site.\n\nType 'wait' to wait back and reunite with the Camp members or Type 'leave' to abandon the place and continue searching for camp members: ")

                if ch == "wait" :

                    print("\nYou stayed behind.You waited for your camp members. After few hours you found them returning to the Base Camp and are Happy to see them again.")
                    print("\nHurray! You have successfully made it to the end.\n")

                elif ch == "leave" :

                    print("\nYou left the site and began to search for your Camp members. You are now far away from the Basecamp. You got lost in the Woods again!")
                    print("\nSorry! You didn't make it to the end. Try again!\n")

                else :

                    print("\nYou made Invalid Choice!\n")

            else :

                print("\nYou made Invalid Choice!\n")

        else :

            print("\nYou made Invalid Choice!\n")

    else :

        print("\nYou made Invalid Choice!\n")

else :

    print("\nYou made Invalid Choice!\n")
    
#<----------------------------------------End of the Program---------------------------------------------------------->
