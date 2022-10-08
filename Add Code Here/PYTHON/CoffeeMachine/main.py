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
profit=0
resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}
def resource_sufficient(order_ing):
    for item in order_ing:
        if order_ing[item] >= resources[item]:
            print(f"Sorry there is not enough {item}.")
            return False
        return True
def coins():
    '''return total coins inserted'''
    print("Please insert coins")
    total = int(input("How many quarters?: ")) * 0.25
    total += int(input("How many dimes?: ")) * 0.10
    total += int(input("How many nickels?: ")) * 0.05
    total += int(input("How many pennies?: ")) * 0.01
    return total
def transaction(money_rec, drink_cost):
    if money_rec >= drink_cost:
        change= round(money_rec - drink_cost ,2)
        print(f"Here is {change}$ change")
        global profit
        profit += drink_cost
        return True
    else:
        print("Sorry that is not enough money. Money refunded.")
        return False  
def make_coffee(drink, order_ing):
    for item in order_ing:
        resources[item] -= order_ing[item]
    print(f"Here is your {drink}")
    
is_on=True

while is_on:
    choice= input("What would you like? (espresso/latte/cappuccino): ")
    if choice =="off":
        is_on=False

    elif choice=="report":

       print(f"Water: {resources['water']}ml") 

       print(f"Milk: {resources['milk']}ml")

       print(f"Coffee: {resources['coffee']}ml")

       print(f"Money: {profit}ml")
    else:
        drink= MENU[choice]
        if resource_sufficient(drink["ingredients"]):
           pay= coins()
           if transaction(pay, drink["cost"]):
               make_coffee(choice, drink["ingredients"])
            
