def reverse_string(s):
  """
  Reverses a given string.
  """
  reversed_str = ""
  for i in range(len(s)-1, -1, -1):
    reversed_str += s[i]
  return reversed_str

def count_vowels(s):
  """
  Counts the number of vowels in a given string.
  """
  vowels = "aeiouAEIOU"
  count = 0
  for char in s:
    if char in vowels:
      count += 1
  return count

def remove_duplicates(s):
  """
  Removes duplicate characters from a given string.
  """
  new_str = ""
  for char in s:
    if char not in new_str:
      new_str += char
  return new_str
# Get user input from terminal
user_input = input("Enter a string: ")

# Call the functions with user input as argument
print("Reversed string:", reverse_string(user_input))
print("Number of vowels:", count_vowels(user_input))
print("String with duplicates removed:", remove_duplicates(user_input))
