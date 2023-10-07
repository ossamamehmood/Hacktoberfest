import random

class VirtualPet:
    def __init__(self, name):
        self.name = name
        self.hunger = 50
        self.happiness = 50

    def feed(self):
        self.hunger -= random.randint(10, 20)
        self.happiness += random.randint(5, 10)

    def play(self):
        self.hunger += random.randint(5, 10)
        self.happiness += random.randint(10, 20)

    def check_status(self):
        if self.hunger < 0:
            self.hunger = 0
        if self.happiness < 0:
            self.happiness = 0
        print(f"{self.name}'s Status:")
        print(f"Hunger: {self.hunger}/100")
        print(f"Happiness: {self.happiness}/100")

def virtual_pet_game():
    print("Welcome to the Virtual Pet game!")
    name = input("Enter a name for your pet: ")
    pet = VirtualPet(name)

    while True:
        print("\nMenu:")
        print("1. Feed")
        print("2. Play")
        print("3. Check Status")
        print("4. Quit")

        choice = input("Enter your choice (1/2/3/4): ")

        if choice == "4":
            print(f"Goodbye! {pet.name} says farewell.")
            break

        if choice == "1":
            pet.feed()
            print(f"You fed {pet.name}.")
        elif choice == "2":
            pet.play()
            print(f"You played with {pet.name}.")
        elif choice == "3":
            pet.check_status()
        else:
            print("Invalid choice. Please choose a valid option (1/2/3/4).")

if __name__ == "__main__":
    virtual_pet_game()
