# Define a dictionary to map color names to hexadecimal color codes
color_codes = {
    "skyblue": "#87CEEB",
    "red": "#FF0000",
    "green": "#008000",
    # Add more color mappings as needed
}

# Function to get the color code for a given color name
def get_color_code(color_name):
    return color_codes.get(color_name.lower(), "Color not found")

# Get the color name from the user
color_name = input("Enter a color name: ")

# Get and print the color code
color_code = get_color_code(color_name)
print(f"The color code for {color_name} is {color_code}")
