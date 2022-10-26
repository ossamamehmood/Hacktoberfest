"""Help on module fileorganizer
NAME
    fileorganizer

DESCRIPTION
    This script allows the user to look through any folder and move the files to their respective subfolders based on the file type.

FUNCTIONS
    cmd_args()
        Splits the command line arguments into source base and destination base

    cleandesk(src_base, dst_base)

"""

import os
import sys
from datetime import datetime
import extensiondict

log = []

def cleandesk(src_base, dst_base):
    """ Copies files from source directory to destionation directory while sorting them according to extension and date of creation

    Parameters:
        src_base(str): path to the source directory
        dst_base(str): path to the destination directory
    """
    for filename in os.listdir(src_base):
        i = 1
        # This splits the file into file name and extension in order to process file type
        split = os.path.splitext(src_base + filename)
        root_name = split[0] # File name
        extension = split[1] # File extension type
        log.append("\n"+f'The file {root_name} is of the type {extension}')

        try:
            # Dest is the final argument for destination folder that I feed into the
            # file copy method. It is updated with the appropriate filetype and year-based
            # directories using conditionals below

            # Determining which folder the file should go into based on extension
            dest = dst_base + extensiondict.getpath(extension.lower())
            log.append("\n"+f'The destination folder based on file type is {dest}')

            # Determining which folder the file should go into based on date of creation
            cdate = os.path.getctime(src_base + filename)
            year = datetime.fromtimestamp(int(cdate)).strftime('%Y')
            log.append("\n"+f'The year of creation for this file is {year}')

            # This adds the year folder to the end of filetype folder
            dest = f'{dest}/{year}'
            log.append("\n"+f"Destination folder with year added is {dest}")

            final_path_exists = os.path.exists(dest)
            log.append("\n"+f"Does the appropriate destination directory exist? {final_path_exists}")

            # Checking to see if the required directory already exists. If not, it is created
            if not final_path_exists:
                os.makedirs(dest)
                final_path_exists = os.path.exists(dest)
                log.append("\n"+"The destination directory has been created.")

            log.append("\n"+f"The filename is {filename}")

            # file_exists_in_dest checks if the specified directory is a file,
            # which indicates that the filename in fact exists. If it does exist,
            # the block underneath this line either creates a new name by appending
            # numbers to the end of the filename or leaves the file alone,
            # based on a decision made by the user

            file_exists_in_dest = os.path.isfile(f'{dest}/{filename}')
            log.append("\n"+f'Does the file already exist in destination? {file_exists_in_dest}')

            filepath = src_base + filename
            log.append("\n"+f"The final source file path is {filepath}")

            file_exists_in_src = os.path.isfile(filepath)

            if file_exists_in_dest:
                moveornot = input(f'{filename} already exists in the destination directory. \
                \nWould you like me to move the file to the destination after renaming \
                it (or) leave it alone? \nPress 1 for the first option and press any \
                other key to choose the second. ')

                if moveornot == '1':
                    while file_exists_in_dest:
                        i += 1
                        newpath = f'{root_name}{i}{extension}'
                        os.rename(filepath, newpath)
                        newpathsplit = newpath.split("/")
                        lastindex = len(newpathsplit)-1
                        newname = newpathsplit[lastindex]
                        movefile(src_base, newname, dst_base)
                        file_exists_in_dest = os.path.isfile(f'{dest}/{newname}')
                        log.append("\n"+'A name clash occurred in the process but was fixed.')
                        filename = newname

                else:
                    log.append("\n"+'Alright, I\'ll leave it alone')
                    log.append("\n"+f'{filename} was not transferred from {src_base} to {dest}')

            else:
                if file_exists_in_src and not file_exists_in_dest:
                    movefile(src_base, filename, dest)

            if not os.path.isfile(src_base + filename):
                log.append("\n"+f'{filename} was deleted from  {src_base} \n\n')

            else:
                log.append("\n"+f'{filename} was not deleted from {src_base} \n\n')

        except Exception:
            _ = extension.lower() not in extensiondict.extension_dict.keys()

    return log
def movefile(src, filename, dst):
    """Moves a file from the source directory to destination directory

    Parameters:
        src (str):  The source directory containing the file
        filename (str): The filename of the file to be moved
        dst(str): The destination directory
    """

    log.append("\n"+"Home Directory is ", os.path.expanduser("~"))
    os.chdir(os.path.expanduser("~"))
    os.chdir(src)
    command = f'move "{filename}" "{dst}"'
    log.append("\n"+f"The final command passed into shell is {command}")
    os.system(command)
    log.append("\n"+f'{filename} was transferred from {src} to {dst}')

    return log

# def run(src_base):
    # src_base, dst_base = cmd_args()
    # cleandesk(src_base, dst_base)

# if __name__ == "__main__":
#     run()
