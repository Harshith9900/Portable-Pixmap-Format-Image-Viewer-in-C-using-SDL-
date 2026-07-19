from PIL import Image

with Image.open("image.png") as img:
    # Convert to RGB to drop any transparency
    img.convert('RGB').save("image.ppm")