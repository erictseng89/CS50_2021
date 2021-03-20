a = input("Do you agree? ")

if a == 'Y' or a == 'y':
	print("Agreed.")
elif a == 'N' or a == 'n':
	print("Not agreed.")
	

s = input("Do you agree? ")

# Using .lower for the variable s 
if s.lower() in ["y", "yes"]:
	print("Agreed")
elif s.lower() in ["n", "no"]:
	print("Disagreed")