# This program will read DNA STR(Short Tandem Repeats) sequences and determine if they belong to a list of people.

# The program will take arguments.First being a csv file containing a list of names along with their DNA counts for a particular STR.

# use sys library for arguments.
import sys
import csv

# Defining main function
def main() :

	# Check command-line arguments. 
	# Check that 2 arguments were inputted. Using the len() functio to see the size of the argv array. The program will print an error message and exit out with error return if the usage is incorrect.
	if len(sys.argv) != 3:
		print("Usage: dna.py list.csv sequence.txt")
		return 1
	
	# Read the CSV file and read contents into memory. I'm using a list with nested dictionary
	with open(sys.argv[1], 'r') as csvFile:
		reader = csv.DictReader(csvFile)
		strList = []
		for row in reader:
			strList.append(row)

	# I need a way to read the STR sequences into memory.
	# Apparently there is a function to list the keys. It is dict.keys. We need to use the 'list' function to list out the outputs.
	key_list = list(strList[0].keys())

	# Creating a dictionary to count max repeats of each STR string.
	strCounter = {}
	for i in range(1, len(key_list), 1):
		strCounter[key_list[i]] = 0
	
	# Opening the sequence file and reading into memory
	with open(sys.argv[2], 'r') as sequenceFile:
		sequence = sequenceFile.read()

	# For all STRs, read through the sequence, starting from start of string towards the end of the string. 
	for i in range(1, len(key_list), 1):
		strCurrent = key_list[i]

		""" # Debugging print
		print('%s has a maximum repeat of %d' %(strCurrent, maxRepeat(sequence, strCurrent)))
		print(strCurrent[0]) """

		# To obtain a substring, we use the slicing operation.
		# newString = oldStrong[index:], will return from startingIndex to the last character
		# newString = oldString[:index] will return from start of string up to but not including the index location.
		# newString = oldString[startingIndex: upToIndex]
		# Creating substrings for potential matches.
		for i in range(len(sequence)):
			# Check if remaining string has enough characters to beat the current max count.
			if strCounter[strCurrent] >= maxRepeat(len(sequence) - i, strCurrent):
				break
			if sequence[i] == strCurrent[0]:
				newSeq = sequence[i:]
				newCount = countRepeat(newSeq, strCurrent)
				if newCount > strCounter[strCurrent]:
					strCounter[strCurrent] = newCount

	print(strCounter)





# From HINT: it may be helpful to start by writing a function that, given both a DNA sequence and an STR as inputs, returns the maximum number of times that the STR repeats.
def maxRepeat(seqLength, STR):
	strlength = len(STR)

	return int(seqLength / strlength)


# Implementing the main checking function
def countRepeat(seq, STR):
	strLength = len(STR)
	count = 0
	for check in range(0, len(seq), strLength):
		tempSeq = seq[check:strLength]
		print(tempSeq)
		if tempSeq == STR:
			count += 1
			print(count)
		else:
			return count
	return count


main()