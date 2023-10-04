# I declare that my work contains no examples of misconduct, such as plagiarism, or collusion.
# Any code taken from other sources is referenced within my code solution.
# Student ID: w1954044
# Date: 28th November 2022

# import the credits_check function from another program
from w1954044 import credits_check

# initiate an empty dictionary
stu_results = {}

# validate the student ID
def stuID_check():
    while True:
        stu_no = input("Enter your Student ID: ").lower()

        if len(stu_no) != 8:
            print("Student ID is worng. Please try again.")
            continue

        elif stu_no[0] != 'w':
            print("Plase check your Student ID again. E.g.:- wxxxxxxx")
            continue

        elif not stu_no[1:].isdigit():
            print("Invalid student ID. Please enter no more than one letter.")
            continue

        if stu_no in stu_results.keys():
            print("The student ID already exist. Please enter a new student ID")
            continue
        
        else:
            return stu_no


# main function runs to give the result to the student
def main():

    user_input = 'y'
    while user_input != 'q':

        credits_pass = credits_check("Enter your total PASS credits: ")
        credits_defer = credits_check("Enter your total DEFER credits: ")
        credits_fail = credits_check("Enter your total FAIL credits: ")

        sum_credits = credits_pass + credits_fail + credits_defer

        if sum_credits != 120:
            print("Total Incorrect.\n")
            continue

        stu_no = stuID_check()

        if int(credits_pass) == 120:
            marks = ("progress - "+ str(credits_pass), str(credits_defer), str(credits_fail))
            result = ', '.join(marks)
            print("Progress")
        
        elif int(credits_pass) == 100:
            marks = ("Module trailer - "+ str(credits_pass), str(credits_defer), str(credits_fail))
            result = ', '.join(marks)
            print("Progress (module trailer)")

        elif int(credits_fail) >= 80:
            marks = ("Exclude - "+ str(credits_pass), str(credits_defer), str(credits_fail))
            result = ', '.join(marks)
            print("Exclude")

        else:
            marks = ("Module retriever - "+ str(credits_pass), str(credits_defer), str(credits_fail))
            result = ', '.join(marks)
            print("Do not progress - module retriever")

        stu_results[stu_no] = result

        print()
        print("Would you like to enter another set of data?")
        while True:
            user_input = input("Enter 'y' for yes or 'q' to quit and view results: ").lower()
            if user_input not in ('y', 'q'):
                print("Please enter a valid input")
                continue
            elif user_input == 'q':
                break 
            else:
                break
        print()
        continue

main()

print()
print("Part 04")

# Assign the keys and vales of the dictionary to variables and print
for uow_no, result in stu_results.items():
    print(uow_no, ':', result, end = ' ')


## References:

    # Python Software Foundation [2022], python standard library. Available at https://docs.python.org/3/library/stdtypes.html#tuples 

    # pyhton Software Foundation [2022], Data stuctures. Available at https://docs.python.org/3/tutorial/datastructures.html















