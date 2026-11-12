from PIL import Image
from pathlib import Path

# Find the project folder
project = Path(__file__).resolve().parent

# Original photo (located inside src)
image_path = project / "src" / "LoganLiv_China.jpg"

# Open the photo
image = Image.open(image_path).convert("RGB")

# Resize to TFT screen size
image = image.resize((240, 240))

# Create the header file inside src
output_path = project / "src" / "LoganLiv_China.h"

with open(output_path, "w") as file:

    file.write("#pragma once\n")
    file.write("#include <Arduino.h>\n\n")

    file.write(
        "const uint16_t LoganLiv_China[57600] PROGMEM = {\n"
    )

    for y in range(240):
        for x in range(240):

            r, g, b = image.getpixel((x, y))

            # Convert RGB to RGB565
            color = (
                ((r & 0xF8) << 8) |
                ((g & 0xFC) << 3) |
                (b >> 3)
            )

            file.write(f"0x{color:04X}, ")

        file.write("\n")

    file.write("};\n")

print("Image converted successfully!")
print("Created:", output_path)