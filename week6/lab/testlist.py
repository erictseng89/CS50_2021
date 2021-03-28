import sys
import csv

def main():
	if len(sys.argv) != 2:
		print("Usage: testlist.py CSVFILE")

	months = []
	with open(sys.argv[1], 'r') as file:
		reader = csv.DictReader(file)
		for row in reader:
			months.append(row)

	# for row in months:
	# 	print(row)
	print(months[0]['days'])

main()