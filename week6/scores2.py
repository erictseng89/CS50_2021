scores = []

for i in range(3):
	 scores.append(int(input("Score: ")))
# append is a function of list inwhich the value it takes in will be added as a new value of the list.

average = sum(scores) / len(scores)
print(f"Average: {average}")