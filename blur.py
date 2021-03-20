from PIL import Image, ImageFilter

before = Image.open("images/courtyard.bmp")
# in C, "." is used as part of structs, in python, you can have functions inside structs.
after = before.filter(ImageFilter.BoxBlur(1))

after.save("out.bmp")
