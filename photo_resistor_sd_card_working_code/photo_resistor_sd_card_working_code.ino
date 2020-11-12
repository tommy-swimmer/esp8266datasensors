/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  This code works as of 11/11/2020
  WORKS FOR ARDUINO ONLY: email tmwimmer@fortlewis.edu for more questions

*/

#include <SPI.h>
#include <SD.h>

File myFile;

//Constants
const int pResistor = 0; // Photoresistor at Arduino analog pin A0

//Variables
int value;          // Store value from photoresistor (0-1023)

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only

  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optiona  
  }
  
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

 
}

void loop() {
  value = analogRead(pResistor);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = value * (5.0 / 1023.0);
  
//  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(1000);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("11_6_test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    
    myFile.println(voltage);
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error logging data");
  }

    // re-open the file for reading:
    myFile = SD.open("11_6_test.txt");
    if (myFile) {

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  }
  
