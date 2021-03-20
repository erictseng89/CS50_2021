import csv 

file = open("phonebook.csv", "a")
# opening file "a" in append mode.

name = input("Name: ")
number = input("Number: ")

# .writer is a function of csv library which allows implements the function of writing to a given "file" of the "open" function. I
writer = csv.writer(file)

writer.writerow([name, number])
# .writerow writes into the current last row, then will add new line.

file.close()

# Alternatively:
# "with" keyword will automatically close the file.
with open("phonebook.csv", "a") as file:
	name = input("Name: ")
	number = input("Number: ")

	writer = csv.writer(file)
	writer.writerow([name, number])
