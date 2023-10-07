import os

def rename_files_in_directory(directory_path, new_name):
    try:
        # Iterate over all files in the directory
        for filename in os.listdir(directory_path):
            if os.path.isfile(os.path.join(directory_path, filename)):
                # Generate the new file name by combining the directory path and new name
                new_filename = os.path.join(directory_path, new_name)
                # Rename the file
                os.rename(os.path.join(directory_path, filename), new_filename)
                print(f"Renamed '{filename}' to '{new_name}'")

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    directory_path = input("Enter the directory path: ")
    new_name = input("Enter the new name for the files: ")
    rename_files_in_directory(directory_path, new_name)
