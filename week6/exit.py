# importing entire sys library
import sys

# will need to refer to library everytime its function is used.
if len(sys.argv) != 2:
	print("Missing command-line argument.")

	#sys.exit is used to exit the program. Use "echo $?" after the program has ended to see exit status
	sys.exit(1)

print(f"hello, {sys.argv[1]}")
# sys.exit(0)