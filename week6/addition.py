x = int(input("What is x? "))
y = int(input("What is y? "))
# We must cast the "input" function to change datatype to integer. By default it will be in ASCII(char or str)
print(x + y)

x = int(input("What is x? "))
y = int(input("What is y? "))

# python will change the datatype from int to float by itself.
z = x / y
print(z)