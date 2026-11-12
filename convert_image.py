from PIL import Image

# Open the picture
image = Image.open("myphoto.png").convert("RGB")

# Resize to fit the TFT screen
image = image.resize((240, 240))

# Create a header file containing image pixels
with open("src/my_image.h", "w") as file:
    file.write("#pragma once\n")
    file.write("#include <Arduino.h>\n\n")
    file.write("const uint16_t myImage[240 * 240] PROGMEM = {\n")

    for y in range(240):
        for x in range(240):
            r, g, b = image.getpixel((x, y))

            # Convert RGB888 to RGB565
            color = (
                ((r & 0xF8) << 8) |
                ((g & 0xFC) << 3) |
                (b >> 3)
            )

            file.write(f"0x{color:04X}, ")

        file.write("\n")

    file.write("};\n")

print("Image converted successfully!")
