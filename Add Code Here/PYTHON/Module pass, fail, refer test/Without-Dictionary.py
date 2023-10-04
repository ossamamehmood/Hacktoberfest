# I declare that my work contains no examples of misconduct, such as plagiarism, or collusion.
# Any code taken from other sources is referenced within my code solution.
# Student ID: w1954044
# Date: 28th November 2022

# Import sys module to use system commands
import sys

# pre-defined variables
progress_count = 0
progress_mt_count = 0
exclude_count = 0
do_not_progress_count = 0


# pre-defined lists
results = []


# User defined functions

# function to get the credits and check the validity of the inputs
def credits_check(input_message):
    while True:
        # Try to convert the input to an int
        try:
            creditz = int(input(input_message).strip())
        
            # Check whether a multiple of 20
            if creditz % 20 != 0:
                print("Out of range.", "\n")
                continue
                
            # Check the range of the input
            elif creditz < 0 or creditz > 120:
                print("Out of range.", "\n")
                continue
      
        except ValueError:
            print("Integer required.", "\n")
            continue
        
        else:
            return creditz


# function to build the histogram with the total outcomes
def histogram(progress_count, progress_mt_count, do_not_progress_count, exclude_count):

    # the star pattern
    star_1 = progress_count * '*'
    star_2 = progress_mt_count * '*'
    star_3 = do_not_progress_count * '*'
    star_4 = exclude_count * '*'

    print("\n---------------------------------------------------------------")

    print("Histogram")

    # the histogram
    print("Progress", progress_count, "\t:", star_1)
    print("Trailer", progress_mt_count, "\t:", star_2)
    print("Retriever", do_not_progress_count, "\t:", star_3)
    print("Excluded", exclude_count, "\t:", star_4)

    print()

    # total outcomes
    total_outcomes = progress_count + progress_mt_count + do_not_progress_count + exclude_count
    print(total_outcomes, "outcomes in total.\n")

    print("---------------------------------------------------------------")



#main program
def main(progress_count, progress_mt_count, do_not_progress_count, exclude_count):
    while True:

        # prompting the menu and get the user to choose between student version and staff version
        try:
            version = int(input("MENU\n1. Staff Version\n2. Student Version\n3. Exit\nEnter your option: "))
            print()
            
        except ValueError:
            print("Please enter only out of the numbers 1, 2, 3")
            continue

        else:
            user_input = 'y'

            if version == 1:
                
                while user_input != 'q':
                    # call the pre defined function and get the credits
                    credits_pass = credits_check("Enter your total PASS credits: ")
                    credits_defer = credits_check("Enter your total DEFER credits: ")
                    credits_fail = credits_check("Enter your total FAIL credits: ")

                    sum_credits = credits_pass + credits_fail + credits_defer

                    if sum_credits != 120:
                        print("Total Incorrect.\n")
                        continue

                    # Get the progression and storing them in a tuple
                    if int(credits_pass) == 120:
                        progress_count += 1
                        marks = ("progress - "+ str(credits_pass), str(credits_defer), str(credits_fail))
                        print("Progress") 

                    elif int(credits_pass) == 100:
                        progress_mt_count += 1
                        marks = ("Module trailer - "+ str(credits_pass), str(credits_defer), str(credits_fail))
                        print("Progress (module trailer)")

                    elif int(credits_fail) >= 80:
                        exclude_count += 1
                        marks = ("Exclude - "+ str(credits_pass), str(credits_defer), str(credits_fail))
                        print("Exclude")

                    else:
                        do_not_progress_count += 1
                        marks = ("Module retriever - "+ str(credits_pass), str(credits_defer), str(credits_fail))
                        print("Do not progress - module retriever")

                    # Join every element in the marks tuple and make a single string
                    a = ', '.join(marks)
                    results.append(a)

                    # Getting and validating the user_input 
                    print()
                    print("Would you like to enter another set of data?")
                    while True:
                        user_input = input("Enter 'y' for yes or 'q' to quit and view results: ").lower()
                        if user_input not in ('y', 'q'):
                            print("Please enter a valid input")
                            continue
                        elif user_input == 'q':
                            return progress_count, progress_mt_count, do_not_progress_count, exclude_count
                        else:
                            break
                    print()
                    continue

            elif version == 2:
                while True:

                    # call the pre defined function and get the credits
                    credits_pass = credits_check("Enter your total PASS credits: ")
                    credits_defer = credits_check("Enter your total DEFER credits: ")
                    credits_fail = credits_check("Enter your total FAIL credits: ")

                    sum_credits = credits_pass + credits_fail + credits_defer

                    if sum_credits != 120:
                        print("Total Incorrect.\n")
                        continue

                    # Get the progression and storing them in a tuple
                    if int(credits_pass) == 120:
                        print("Progress")

                    elif int(credits_pass) == 100:
                        print("Progress (module trailer)")

                    elif int(credits_fail) >= 80:
                        print("Exclude")

                    else:
                        print("Do not progress - module retriever")

                    break

            elif version == 3:
                print('Exiting...')
                sys.exit()

            else:
                print("Please enter a valid option.")
                continue



if __name__ == "__main__":
    # main program
    progress_counter, progress_mt_counter, do_not_progress_counter, exclude_counter = main(progress_count, progress_mt_count, do_not_progress_count, exclude_count)

    # histogram
    histogram(progress_counter, progress_mt_counter, do_not_progress_counter, exclude_counter)


    # part 2
    print("Part 02")

    # remove the commas and brackets of the list and print line by line
    print(*results, sep = "\n")


    # part 3
    print("\n---------------------------------------------------------------")
    print("Part 03")
    
    # Write the data stored in the list to a file
    with open('results_file.txt', 'w') as file:
        for i in results:
            file.write(f"{i}\n")

    # Read the file and get the stored data from the file
    with open('results_file.txt') as file:
        content = file.read()
        print(content)



## References

        # Python Software Foundation [2022], python standard library. Available at https://docs.python.org/3/library/stdtypes.html#tuples

        # pyhton Software Foundation [2022], python runtime servises, sys. Available at https://docs.python.org/3/library/sys.html

        # pyhton Software Foundation [2022], Data stuctures. Available at https://docs.python.org/3/tutorial/datastructures.html
