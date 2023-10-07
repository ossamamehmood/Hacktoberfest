def todo_list():
    tasks = []

    print("Welcome to the ToDo List program!")
    
    while True:
        print("\nMenu:")
        print("1. Add Task")
        print("2. View Tasks")
        print("3. Mark Task as Completed")
        print("4. Quit")
        
        choice = input("Enter your choice: ")
        
        if choice == "1":
            task = input("Enter a new task: ")
            tasks.append(task)
            print(f"Task '{task}' added to the list.")
        elif choice == "2":
            if len(tasks) == 0:
                print("No tasks in the list.")
            else:
                print("\nTasks:")
                for i, task in enumerate(tasks, start=1):
                    print(f"{i}. {task}")
        elif choice == "3":
            if len(tasks) == 0:
                print("No tasks in the list.")
            else:
                try:
                    index = int(input("Enter the task number to mark as completed: ")) - 1
                    if 0 <= index < len(tasks):
                        completed_task = tasks.pop(index)
                        print(f"Task '{completed_task}' marked as completed.")
                    else:
                        print("Invalid task number.")
                except ValueError:
                    print("Please enter a valid task number.")
        elif choice == "4":
            print("Goodbye! Thanks for using the ToDo List program.")
            break
        else:
            print("Invalid choice. Please choose a valid option.")

if __name__ == "__main__":
    todo_list()
