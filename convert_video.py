
from PIL import Image
from pathlib import Path

# Find video frames (only 5 for testing)
frames = sorted(Path("frames").glob("frame_*.png"))[:5]

if not frames:
    raise FileNotFoundError("No frames found!")

# Create header file for Arduino
with open("src/video_frames.h", "w") as file:
    file.write("#pragma once\n")
    file.write("#include <Arduino.h>\n\n")

    for index, path in enumerate(frames):
        image = Image.open(path).convert("RGB")
        image = image.resize((240, 240))

        # Convert each frame to RGB565 format
        file.write(
            f"const uint16_t videoFrame{index}[57600] "
            "PROGMEM = {\n"
        )

        # Read ALL 240 x 240 pixels
        for y in range(240):
            for x in range(240):
                r, g, b = image.getpixel((x, y))

                color = (
                    ((r & 0xF8) << 8) |
                    ((g & 0xFC) << 3) |
                    (b >> 3)
                )

                file.write(f"0x{color:04X}, ")

            file.write("\n")

        file.write("};\n\n")

    # Store pointers to all frames
    file.write("const uint16_t* const videoFrames[] = {\n")

    for index in range(len(frames)):
        file.write(f"    videoFrame{index},\n")

    file.write("};\n")

    file.write(
        f"const int videoFrameCount = {len(frames)};\n"
    )

print(f"Converted {len(frames)} frames!")