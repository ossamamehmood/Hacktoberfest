# Display the author's name
print("Written by Abhi :)")

# Prompt the user to input a list of bytes separated by commas
input_bytes_str = input("Enter the bytes (comma-separated): ")

# Split the input string into a list of byte strings and convert them to integers
input_bytes_list = [int(byte_str.strip()) for byte_str in input_bytes_str.split(',')]

# Create a byte array from the list of integers
byte_array = bytearray(input_bytes_list)

try:
    # Attempt to decode the byte array using UTF-8 encoding
    result_string = byte_array.decode('utf-8')

    # If successful, display the decoded string
    print("Decoded String:", result_string)
except UnicodeDecodeError:
    # If decoding fails, display an error message
    print("Error: Unable to decode the provided bytes.")