# CSV stands for comma seperated values. Python has a library with functions to interact with csv files.
import csv

# The csv module implements classes to read and write tabular data in CSV format.

# csv.reader
# csv.reader(csvfile, dialect='excel', **fmtparams)
# where fmtparams are dialects and formatting parameters.
# Return a reader object which  will iterate over lines in the given csvfile. 

import csv
with open('eggs.csv', newline = "") as csvfile:
	spamreader = csv.reader(csvfile, delimiter = "", quotechar = "|")
	for row in spamreader:
		print(', '.join(row))


# csv.writer
# csv.writer(csvfile, dialect='excel', **fmtparams)
# Retrun a writer object responsible for converting the user's data into delimited strings on the given file-like object.

import csv
with open('eggs.csv', 'w', newline='') as csvfile:
	spamwriter = csv.writer(csvfile, delimiter=' ', quotechar = '|', quoting=csv.QUOTE_MINIMAL)
	spamwriter.writerow(['Spam' * 5 + ['Baked Beans'])
	spamwriter.writerow(['Spam', 'Lovely Spam', 'Wonderful Spam'])


# csv.DictReader
# csv.DictReader(f, fieldnames=None, restkey=None, restval=None, dialect='excel', *args, **kwds)
# Create an objec that operates like a regular reader but maps the information in each row to a dict whose keys are given by the optional fieldnames parameter.
# fieldnames should be used if the csv file's first row does not contain the column headings, but instead starts to display the data immediately.
# If fieldnames is omitted, the values in the first row of file will be used as the fieldnames. Regardless of how the fieldnames are determined, the dictionary preverves their original ordering.
# If a row has more fields than fieldnames, The remaining data is put in a list and stored with the fieldname specified by restkey (which defaults to None). If a blank row has fewer fields than fieldnames, the missing values are filled-in with the value of restval (which defaults to None)

import csv
with open('names.csv', newline="") as csvfile:
	reader = csv.DictReader(csvfile)
	for row in reader:
		print(row['first_name'], row['last_name'])

# output:
Eric Idle
John Cleese

# command:
print(row)

# output:
{'first_name': 'John', 'last_name': 'Cleese'}


