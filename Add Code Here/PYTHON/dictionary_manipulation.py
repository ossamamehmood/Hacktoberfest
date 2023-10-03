'''
@Author: hariom09090
'''

# Initialize an empty dictionary
scores = {}

# Function to add a student and their score to the dictionary
def addStudent():
    name = input("Enter the student's name: ")
    score = int(input(f"Enter {name}'s score: "))
    scores[name] = score

# Function to remove a student from the dictionary
def removeStudent():
    name = input("Enter the name of the student to remove: ")
    if name in scores:
        del scores[name]
        print(f"{name} has been removed.")
    else:
        print(f"{name} is not in your dictionary.")

# Function to display all students and their scores
def displayStudent():
    if not scores:
        print("The scores dictionary is empty.")
    else:
        print("Student Scores:")
        for name, score in scores.items():
            print(f"{name}: {score}")

# Main program loop
while True:
    print("\nOptions:")
    print("1. Add a student and score")
    print("2. Remove a student")
    print("3. Display student scores")
    print("4. Exit")
    
    choice = input("Enter your choice (1/2/3/4): ")
    
    if choice == "1":
        addStudent()
    elif choice == "2":
        removeStudent()
    elif choice == "3":
        displayStudent()
    elif choice == "4":
        break
    else:
        print("Invalid choice. Please enter 1, 2, 3, or 4.")

print("Exit")
