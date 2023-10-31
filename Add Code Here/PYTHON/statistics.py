from statistics import mean, median, mode

# Function to get a list of numbers from the user
def get_numbers():
    input_str = input("Enter a list of numbers separated by spaces: ")
    numbers = [float(x) for x in input_str.split()]
    return numbers

# Get the list of numbers from the user
numbers = get_numbers()

# Calculate the mean, median, and mode
mean_value = mean(numbers)
median_value = median(numbers)
try:
    mode_value = mode(numbers)
except StatisticsError:
    mode_value = "No unique mode found"

# Display the results
print("Mean:", mean_value)
print("Median:", median_value)
print("Mode:", mode_value)
