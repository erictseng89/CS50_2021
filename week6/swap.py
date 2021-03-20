# python removes pointers and memory controls from the programmer to prevent segementation faults

x = 1
y = 2

print(f"x is {x}, y is {y}")
x, y = y, x
# we no longer require a temporary variable
print(f"x is {x}, y is {y}")