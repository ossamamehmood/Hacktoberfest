import csv

# Function to update employee information by Employee ID
def update_employee_info(employee_id, new_data):
    # Read the CSV file into a list of dictionaries
    with open('employee_data.csv', mode='r') as file:
        reader = csv.DictReader(file)
        employees = list(reader)

    # Find the employee with the matching ID
    for employee in employees:
        if employee['Employee ID'] == employee_id:
            # Update the employee's information
            employee.update(new_data)

    # Write the updated data back to the CSV file
    with open('employee_data.csv', mode='w', newline='') as file:
        fieldnames = ['Employee ID', 'First Name', 'Last Name', 'Position', 'Salary']
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(employees)

# Get input from the user
employee_id_to_update = input("Enter the Employee ID to update: ")
new_first_name = input("Enter the new First Name: ")
new_last_name = input("Enter the new Last Name: ")
new_position = input("Enter the new Position: ")
new_salary = input("Enter the new Salary: ")

# Create a dictionary with the new data
new_employee_data = {
    'Employee ID': employee_id_to_update,
    'First Name': new_first_name,
    'Last Name': new_last_name,
    'Position': new_position,
    'Salary': new_salary
}

# Call the update_employee_info function with user input
update_employee_info(employee_id_to_update, new_employee_data)
