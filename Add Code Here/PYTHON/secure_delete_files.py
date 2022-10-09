import os

def secure_delete(path, passes=1):
    with open(path, "ba+") as delfile:
        length = delfile.tell()
    with open(path, "br+") as delfile:
        for i in range(passes):
            delfile.seek(0)
            delfile.write(os.urandom(length))
    os.remove(path)

path=input("Enter the path or file location to be deleted: ")

if os.path.isfile(path):
    secure_delete(path)
elif os.path.isdir(path):
    for root, dirs, files in os.walk(path):
        for file in files:
            secure_delete(os.path.join(root, file))
    try:
        os.rmdir(path)
    except OSError:
        print("Directory is not empty.")
else:
    print("The path does not exist")
