scores = [72, 73, 33]


""" print("Average: " + (sum(scores) / len(scores))) """
# The "len" will return the number of values in a given list.

# The above will return the error:
# TypeError: can only concatenate str (not "float") to str
# This is because python does not like to concatenate a float value to a string. 
# In order to fix this issue, we can cast the float into a string:

print("Average " + str((sum(scores) / len(scores))))

# You can also wrap the functions themselves inside the print("") contents, which can remove the need for the str() cast function as python will presume that I intended for the value be converted into a str. This can cause the print content to be longer and messier to read.

print(f"Average {((sum(scores) / len(scores)))}")

