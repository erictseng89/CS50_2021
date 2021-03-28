# This program will read DNA STR(Short Tandem Repeats) sequences and determine if they belong to a list of people.

# The program will take arguments.First being a csv file containing a list of names along with their DNA counts for a particular STR.

# use sys library for arguments.
import sys

# Defining main function
def main() :

	# Check command-line arguments. 
	# Check that 2 arguments were inputted. Using the len() functio to see the size of the argv array. The program will print an error message and exit out with error return if the usage is incorrect.
	if len(sys.argv) != 3:
		print("Usage: dna.py list.csv sequence.txt")
		return 1
	
	# Check that both files can be open
	list = open(argv[1], "r")
	

	











main()