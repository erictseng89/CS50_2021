# To create a function to print meow, we use the "def" which stands for define.
# Functions are are called must be defined before they are used. This means that without implementing a main() function, you will need to define functions before they are used, which oftentimes means before main.
# Note that though it is not necessary to define the main function, we should nevertheless define it so that we can order other functions below it in a concise manner. Then at the end of the program, call main after all the functions have been defined.

def main():
	for i in range(3):
		meow()

def meow():
	print("meow")

main()