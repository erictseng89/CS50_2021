def main ():
	# Prompt user for height. Re-prompt if it is not between 1 and 8 inclusive.
	while True:
		height = input("Height: ")
		if height.isnumeric():
			height = int(height)
			if height >= 1 and height <= 8:
				break
	
	# Loop to print pyramid
	for i in range(1, height + 1, 1):
		space =  height - i
		print(" " * space, end = "")
		print("#" * i, end = "")
		print(" " * 2, end = "")
		print("#" * i)

main()