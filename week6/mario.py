""" In python, the print() function will, by default, add a "\n" after the print contents. The reason is: 
In python, print() actually has arguments. And specific to this issue, there is an argument called "end" which by default has a value of "\n"; end = "\n".
You can change the value of end to whatever you like. """


""" def main():
	for i in range(3):
		print("?") """
		

""" def main():
	for i in range(4):
		print("?", end = "")
	print()
# Having empty "" will change from adding a new line, to adding nothing. """

def main():
	print("?" * 4)
# You can also use the * multiplier to perform print contents multiple times.



main()

	