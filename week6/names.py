import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

if "Ron" in names:
	print("Found Ron")
	sys.exit(0)
else:
	print("Did not find Ron")
	sys.exit(1)