import pandas as pd
print("A program to convert csv file into Excel sheet")
a=input("Enter the file location")
read_file = pd.read_csv (r f"{a}")
read_file.to_excel (r'Path to store the Excel file\File name.xlsx', index = None, header=True)
