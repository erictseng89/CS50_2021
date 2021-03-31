import csv

def main():
	title = input("Title: ")

	with open("src7/favorites/Favorite TV Shows - Form Responses 1.csv", "r") as file:
		reader = csv.DictReader(file)
		counter = 0
		for row in reader:
			if row["title"].strip().upper() == title.strip().upper():
				counter += 1


	print(counter)





if __name__ == "__main__":
	main()