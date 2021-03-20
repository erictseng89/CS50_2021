# dict is a new data type in python and it is defined by {}, and where key and value are seperated via colon. The value is called a key-value pair.

people = {
	"Brian": "0945-345-123",
	"Ted": "0945-456-123"
}

name = input("Name: ")
if name in people:
	print(f"Number: {people[name]}")
	# in this instance people[name] will return the value for the key of [name]. It will automatically search through as a hash table to approach constant time.
else:
	print("Name not found.")

