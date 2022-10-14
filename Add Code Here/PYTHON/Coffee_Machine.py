MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}
resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}


def calculate_change(cost, money):
    return (cost-money)


total_bill = 0
machine_off = False
while machine_off==False:
    coins = 0
    quarters = 0
    dimes = 0
    nickles = 0
    pennies = 0
    consumer_choice = input("Enter espresso/ latte/ cappuccino:")
    if(consumer_choice == "off"):
        machine_off = True
        print(f"Your total bill amount is: {total_bill}")
        break
    elif(consumer_choice == "reports"):
        print(f"""Amount of water remaining in the tank is {resources['water']}, amount of milk remaining in the tank is
        {resources['milk']}, amount of coffee powder remaining in the tank is {resources['coffee']}""")
        print(f"Your total bill amount is: {total_bill}")
    else:
        if(consumer_choice=='espresso'):
            if((resources['water'] > MENU["espresso"]['ingredients']['water']) and (MENU["espresso"]['ingredients']['coffee'] < resources['coffee'])):
                print(f"That would be {MENU[consumer_choice]['cost']}")
                quarters = int(input("Enter number of quarters:"))
                dimes = int(input("Enter number of dimes:"))
                nickles = int(input("Enter number of nickles:"))
                pennies = int(input("Enter number of pennies:"))
                m = quarters*0.25 + dimes*0.1 + nickles*0.05 + pennies*0.01
                if(m>MENU[consumer_choice]['cost']):
                    print(f"Here is you {consumer_choice}, enjoy!")
                    print(calculate_change(MENU[consumer_choice]['cost'], m))
                    resources['water'] -= MENU["espresso"]['ingredients']['water']
                    resources['coffee'] -= MENU["espresso"]['ingredients']['coffee']
                    total_bill += MENU[consumer_choice]['cost']
                else:
                    print("You dont have enough money.")
            else:
                print("Not enough resources for espresso.")
        else:
            if((resources['water'] > MENU[consumer_choice]['ingredients']['water']) and (MENU[consumer_choice]['ingredients']['coffee'] < resources['coffee']) and (MENU[consumer_choice]['ingredients']['milk'] < resources["milk"])):
                print(f"That would be {MENU[consumer_choice]['cost']}")
                quarters = int(input("Enter number of quarters:"))
                dimes = int(input("Enter number of dimes:"))
                nickles = int(input("Enter number of nickles:"))
                pennies = int(input("Enter number of pennies:"))
                m = quarters * 0.25 + dimes * 0.1 + nickles * 0.05 + pennies * 0.01
                if(m>MENU[consumer_choice]['cost']):
                    print(f"Here is you {consumer_choice}, enjoy!")
                    print(calculate_change(MENU[consumer_choice]['cost'], m))
                    resources['water'] -= MENU[consumer_choice]['ingredients']['water']
                    resources['coffee'] -= MENU[consumer_choice]['ingredients']['coffee']
                    resources['milk'] -= MENU[consumer_choice]['ingredients']['milk']
                    total_bill += MENU[consumer_choice]['cost']
                else:
                    print("You dont have enough money.")
            else:
                print(f"Not enough resources for {consumer_choice}.")
