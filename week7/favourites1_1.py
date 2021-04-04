import csv

def main() :
	titles = []
	with open("src7/favorites/Favorite TV Shows - Form Responses 1.csv", "r") as file:
		reader = csv.DictReader(file)
		for row in reader:
			titles.append(row)
	
	print(titles)







if __name__ == "__main__":
	main()