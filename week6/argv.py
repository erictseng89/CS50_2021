# if you want to access command-line arguments, you need to import a module from the "sys" library.

from sys import argv

if len(argv) == 2:
	print(f"hello, {argv[1]}")
else:
		print("hello, world")

# notice that where in c, the number of arguments is referred to as int argc, in python you simply use the len function len(argv) since "argv" is a list.

# another use case for "for" is to interate over every value in a list:

for arg in argv:
	print(arg)
	