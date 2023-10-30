import os

def create_folder_structure_file(root_path, output_file, depth=0):
    with open(output_file, 'a') as file:
        for item in os.listdir(root_path):
            item_path = os.path.join(root_path, item)
            if os.path.isdir(item_path):
                file.write(f"{'  ' * depth}- {item}/\n")
                create_folder_structure_file(item_path, output_file, depth + 1)
            else:
                file.write(f"{'  ' * depth}- {item}\n")

if __name__ == "__main__":
    # Replace with your folder path which you want to create the structure of
    folder_path = "C:/Users/SAHIL/Desktop/Python/test"  
    
    output_file = "folder_structure.txt"
    
   
    if os.path.exists(folder_path) and os.path.isdir(folder_path):
     
        with open(output_file, 'w') as file:
            file.write(f"- {os.path.basename(folder_path)}/\n")
    
        create_folder_structure_file(folder_path, output_file)
        print(f"Folder structure written to {output_file}")
    else:
        print(f"The specified folder path '{folder_path}' does not exist.")
