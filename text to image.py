import easyocr

# Initialize the reader with English language support
reader = easyocr.Reader(["en"])

# Corrected image path
image_path = r"C:\Users\Administrator\Desktop\we.PNG"

# Read the text from the image
results = reader.readtext(image_path)

# Print the results
for result in results:
    print(result)
