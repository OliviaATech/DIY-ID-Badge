
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_SSD1306.h>

// Video frames for TFT (currently disabled)
// #include "video_frames.h"

// Bunny image (currently enabled)
//#include "my_image.h"

//Photo of me and logan
#include "LoganLiv_China.h"

// ===============================
// TFT DISPLAY PINS
// ===============================

#define TFT_CS    3   // D1
#define TFT_DC    4   // D2
#define TFT_RST   5   // D3
#define TFT_SCLK  8   // D8
#define TFT_MOSI  10  // D10

// Software SPI for TFT
Adafruit_ST7789 tft = Adafruit_ST7789(
    TFT_CS,
    TFT_DC,
    TFT_MOSI,
    TFT_SCLK,
    TFT_RST
);

// ===============================
// OLED DISPLAY PINS
// ===============================

#define OLED_SDA 6  // D4
#define OLED_SCL 7  // D5

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 oled(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

// ===============================
// OLED PERSONAL INFORMATION
// ===============================

void showOLEDInfo() {

    oled.clearDisplay();

    // White pixels ON, black pixels OFF
    oled.setTextColor(SSD1306_WHITE);

    // First name - Large text
    oled.setTextSize(2);
    oled.setCursor(0, 0);
    oled.println("Olivia");

    // Last name - Large text
    oled.setCursor(0, 16);
    oled.println("Anderson");

    // Major - Small text
    oled.setTextSize(1);
    oled.setCursor(0, 36);
    oled.println("Robotics & AI");

    // Email - Small text
    oled.setTextSize(1);
    oled.setCursor(0, 48);
    oled.println("Olivia.H.Anderson");
    oled.setCursor(0, 56);
    oled.println(".Tech@...");

    // Update OLED screen
    oled.display();
}

// ===============================
// SETUP
// ===============================

void setup() {

    Serial.begin(115200);
    delay(1000);

    Serial.println("Starting ID Badge...");

    // Initialize TFT
    tft.init(240, 240);
    tft.setRotation(2);
    tft.fillScreen(ST77XX_BLACK);

    Serial.println("TFT initialized!");

    // Display static bunny image
    tft.drawRGBBitmap(
        0,
        0,
        // myImage, uncomment for bunny image
        LoganLiv_China, // uncomment for photo of me and logan
        240,
        240
    );

    // Initialize OLED
    Wire.begin(OLED_SDA, OLED_SCL);

    if (!oled.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
    )) {
        Serial.println("OLED initialization failed!");
    } else {
        Serial.println("OLED initialized!");
        showOLEDInfo();
    }
}

// ===============================
// MAIN LOOP
// ===============================

void loop() {

    // Video animation (currently disabled)
    /*
    // Play video continuously on TFT
    for (int i = 0;
         i < sizeof(videoFrames) / sizeof(videoFrames[0]);
         i++) {

        tft.drawRGBBitmap(
            0,
            0,
            videoFrames[i],
            240,
            240
        );

        delay(200);
    }
    */
}