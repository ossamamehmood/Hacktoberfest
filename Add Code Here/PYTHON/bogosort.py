import random
import matplotlib.pyplot as plt

# Function to check if a list is sorted
def is_sorted(arr):
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

# Function to perform Bogosort and visualize the progress
def bogosort(arr):
    steps = 0  # Count the number of steps
    sorted_steps = []  # To store the number of elements in sorted order at each step

    while not is_sorted(arr):
        random.shuffle(arr)
        steps += 1
        sorted_count = sum(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))
        sorted_steps.append(sorted_count)

    return arr, steps, sorted_steps

# Initialize a list to be sorted
my_list = [5, 2, 9, 1, 5, 6]

# Perform Bogosort and collect progress data
sorted_list, total_steps, sorted_step_data = bogosort(my_list)

# Plot the progress
plt.figure(figsize=(10, 5))
plt.plot(range(total_steps), sorted_step_data, marker='o', linestyle='-')
plt.xlabel('Steps')
plt.ylabel('Number of Elements in Sorted Order')
plt.title('Bogosort Progress')
plt.grid(True)
print("yaha hu me ")
print(f'Sorted List: {sorted_list}')
print(f'Total Steps: {total_steps}')
plt.show()
