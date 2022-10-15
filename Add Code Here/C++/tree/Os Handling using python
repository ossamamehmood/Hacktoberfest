# This Python code is for Python version : 2.7.12

def show_directories(dir_list, path):
	""" A function that lists the directories """
	import os
	s = "%s%d%s"%("\n", len(dir_list), " directories of " + os.path.abspath(path))
	l = len(s)
	print(s)
	print("="*l)
	for index, dir in enumerate(dir_list):
		print(str(index+1) + ") ", dir)


def show_files(file_list, path):
	""" A function that lists the files """

	import os
	s = "%s%d%s"%("\n", len(file_list), " files of " + os.path.abspath(path))
	l = len(s)
	print(s)
	print("="*l)
	for index, file in enumerate(file_list):
		print(str(index+1) + ") ", file)


def show_cwd_contents( path="." ):
	# A function that calls 2 functions to separately
	# listing out directories and files.
	# It takes a default argument as cwd(.). We can
	# pass other paths too.
	import os

	f_list = []
	d_list = list()

	try:
		for f in os.listdir(path):
			if os.path.isfile(os.path.join(path, f)):
				f_list.append(f)
			else:
				if os.path.isdir(os.path.join(path, f)):
					d_list.append(f)
	except:
		print("\nError, once check the path")
		return

	show_files(f_list, path)

	show_directories(d_list, path)


if __name__ == "__main__":

	# If this module is imported in other module then
	# we need to separately call show_cwd_contents() Or
	# show_cwd_contents(path).
	show_cwd_contents()
	show_cwd_contents("Users\Manish\Desktop\Data Strucures")
