/*

ESP8266 Photoresistor by Tommy Swimmer
Read values from a photoresistor to a 128x32 OLED display.

This sketch works as of 10/08/2020. 

TO-DO:
- Add sd card storage.

See GitHub for pinout directions.

 */
// Necessary libraries for OLED display.
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }



}

void loop() {
// the setup routine runs once when you press reset:

    // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

//  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(1000);

   // OLED Display
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(15,15);
  display.print("Voltage: ");
  display.print(voltage);
  display.print(" V");
  display.display();
  delay(1000);
  display.clearDisplay();


}
