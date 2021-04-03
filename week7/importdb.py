import csv
from cs50 import SQL

def main() :
	open("shows.db", "w").close()
	# This creates a file called show.db, and closes it immediately.

	db = SQL("sqlite:///shows.db")
	db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
	db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")

	with open("src7/favorites/Favorite TV Shows - Form Responses 1.csv", "r") as file:
		reader = csv.DictReader(file)
		for row in reader:
			title = row["title"].strip().upper()
			id = db.execute("INSERT INTO shows (title) VALUES(?)", title)
			for genre in row["genres"].split(", "):
				db.execute("INSERT INTO genres (show_id, genre) VALUES (?, ?)", id, genre)



if __name__ == "__main__":
	main()