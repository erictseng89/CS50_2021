import sys

def main():
	# Prompt user for card number
	number = input("Number: ")

	# Check card length and 
	length = len(number)
	if length < 13 or length > 16:
		print("INVALID")
		return 1
	
	if validcheck(number) and typecheck(number):
		return 0
	else:
		print("INVALID")
		return 1


# This function checks the number to see if it has the correct starting number, and that it will pass the validity check.
def validcheck(n):
	# Check starting number to
	cardstart = [3, 4, 5]
	if int(n[0]) in cardstart:
		print("cardstart found")

		# Variables to help check
		l = len(n)
		check = 0
		count = 0
		for i in range(l-1, -1, -1):
			if (count % 2) == 0:
				check += int(n[i])
				count += 1
			else:
				temp = int(n[i]) * 2
				if temp > 9:
					temp = 1 + (temp % 10)
				count += 1
				check += temp

		if check % 10 == 0:
			return True
	else:
		return False

def typecheck(n):
	# List all possible starts
	amex = [34, 37]
	mc = [51, 52, 53, 54, 55]
	visa = "4"

	# Variable for checking start of AMEX and MC
	head = int(n[0] + n[1])
	if (n[0]) == visa:
		print("VISA")
		return True
	elif head in amex:
		print("AMEX")
		return True
	elif head in mc:
		print("MASTERCARD")
		return True
	else:
		return False
	
main()