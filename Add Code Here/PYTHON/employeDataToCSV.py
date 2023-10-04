import csv

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


    with open('employee_data.csv', mode='w', newline='') as file:
        fieldnames = ['Employee ID', 'First Name', 'Last Name', 'Position', 'Salary']
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(employees)


employee_id_to_update = '101'
new_employee_data = {
    'Employee ID': '101',
    'First Name': 'John',
    'Last Name': 'Doe',
    'Position': 'Manager',
    'Salary': '75000'
}

update_employee_info(employee_id_to_update, new_employee_data)
