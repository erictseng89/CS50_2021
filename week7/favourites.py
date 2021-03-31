import csv

def main () :
	# Using set() to create a list with no duplicates
	titles = {}
	with open("src7/favorites/Favorite TV Shows - Form Responses 1.csv", "r") as file:
		reader = csv.DictReader(file)
		for row in reader:
			title = row["title"].strip().upper()
			if title not in titles:
				titles[title] = 0
			titles[title] += 1

			# If using csv.reader, may need to skip first row for header.
			""" reader = csv.reader(file)
			next(reader)
			for row in reader:
				print(row[1]) """

	for title in sorted(titles, key=lambda title: titles[title], reverse=True):
		print(title, titles[title])



if __name__ == "__main__":
	main()