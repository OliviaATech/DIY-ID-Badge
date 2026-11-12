# DIY-ID-Badge

My DIY ID badge project features a custom circuit board, image and video converters, and embedded programming using the Seeed Studio XIAO ESP32-C3 microcontroller.

This project creates a portable, battery-powered ID badge that displays personal information, custom images, and short video animations.

## Project Features

- Custom image converter for TFT display compatibility.
- Video converter for creating short animations on the TFT.
- OLED display for personal information, such as name and email.
- Physical ON/OFF switch for controlling battery power.
- Rechargeable LiPo battery for portable use.
- Custom soldered circuit assembled on double-sided prototype PCB boards.

## Hardware Components

| Component | Description |
|---|---|
| Microcontroller | Seeed Studio XIAO ESP32-C3 |
| TFT Display | 1.54-inch ST7789 IPS TFT, 240×240 resolution |
| OLED Display | 0.96-inch SSD1306 OLED, 128×64 resolution |
| Battery | 3.7V 1000mAh rechargeable LiPo battery |
| Power Switch | 3-pin slide switch |
| Circuit Board | Double-sided prototype PCB |
| Battery Connector | 2-pin micro connector with wires |
| Additional Materials | Solder, flux, connecting wires, and heat-shrink tubing |

## Software and Programming

**Development Environment**
- Visual Studio Code
- PlatformIO
- Arduino Framework
- C/C++
- Python
- FFmpeg

**Libraries**
- `Arduino.h`
- `Wire.h`
- `Adafruit_GFX.h`
- `Adafruit_ST7789.h`
- `Adafruit_SSD1306.h`
- `PIL` (Python Pillow)

## Display Configuration

### TFT Display — ST7789

The TFT display is used to show custom images and short video animations.

**Resolution:** 240×240 pixels  
**Communication:** SPI

| TFT Pin | XIAO ESP32-C3 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SCL / SCLK | D8 (GPIO8) |
| SDA / MOSI | D10 (GPIO10) |
| RES / RST | D3 (GPIO5) |
| DC | D2 (GPIO4) |
| CS | D1 (GPIO3) |
| BLK | 3V3 |

### OLED Display — SSD1306

The OLED display is used to display personal information, including a name and email address.

**Resolution:** 128×64 pixels  
**Communication:** I2C  
**I2C Address:** `0x3C`

| OLED Pin | XIAO ESP32-C3 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | D4 (GPIO6) |
| SCL | D5 (GPIO7) |

## Image Converter

The image converter allows custom JPG or PNG images to be converted into a format compatible with the ST7789 TFT display.

The conversion process includes:

1. Loading the original image using Python and Pillow.
2. Resizing the image to match the TFT display resolution.
3. Converting pixel colors into RGB565 format.
4. Generating a C/C++ header file (`.h`) containing the image data.
5. Including the generated header file in the PlatformIO project.

The converted image can then be displayed using the Adafruit ST7789 library.

## Video Converter

The video converter allows short videos or animations to be converted into individual frames for playback on the TFT display.

The conversion process includes:

1. Using FFmpeg to extract frames from the original video.
2. Adjusting the frame rate and resolution to reduce memory usage.
3. Using Python and Pillow to process the extracted frames.
4. Converting each frame into RGB565 pixel data.
5. Generating a C/C++ header file containing the video frames.
6. Displaying frames sequentially on the TFT to simulate video playback.

**Important:** Video conversion requires additional optimization because the XIAO ESP32-C3 has limited memory. Frame count, image resolution, and playback speed must be adjusted to maintain compatibility.

During initial development, a reduced frame count was used to test video playback.

## Power and Circuit Design

The badge uses a rechargeable 3.7V LiPo battery connected to the XIAO ESP32-C3 through a physical power switch.

The physical switch interrupts the battery's positive connection to the microcontroller, allowing the badge to be powered ON or OFF without relying on software.

**Power Connections:**

| Connection | Destination |
|---|---|
| Battery Positive (+) | Switch terminal 1 |
| Switch terminal 2 | XIAO BAT+ |
| Battery Negative (−) | XIAO BAT− |
| Switch terminal 3 | Unused |

The TFT and OLED displays receive 3.3V power from the XIAO.

The hardware is assembled using double-sided prototype PCB boards, with soldered connections and a compact layout designed for portability.

## Testing and Debugging

Throughout development, several hardware and software tests were performed, including:

- Continuity testing using a digital multimeter.
- Battery voltage and polarity verification.
- Testing physical ON/OFF switch functionality.
- Debugging TFT and OLED communication.
- Correcting display orientation and wiring connections.
- Testing image conversion and display rendering.
- Optimizing video frames to meet microcontroller memory limitations.
- Testing battery-powered operation without a USB connection.

## Project Goal

This project combines embedded systems programming, electronics, soldering, and image processing to develop a functional, portable ID badge.

This project also serves as hands-on experience in circuit design, hardware integration, software debugging, and microcontroller development.

## Future Improvements

- Improve video conversion efficiency and playback.
- Optimize memory usage for longer animations.
- Improve the physical casing and overall badge design.
- Continue refining the PCB layout and wire management.
- Implement additional display customization options.
