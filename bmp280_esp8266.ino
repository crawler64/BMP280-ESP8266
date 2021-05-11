/***************************************************************************
This is a library for the BMP280 humidity, temperature & pressure sensor
 
Designed specifically to work with the Adafruit BMEP280 Breakout 
----> http://www.adafruit.com/products/2651
 
These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
to interface.
 
Adafruit invests time and resources providing this open source code,
please support Adafruit andopen-source hardware by purchasing products
from Adafruit!
 
Written by Limor Fried & Kevin Townsend for Adafruit Industries. 
BSD license, all text above must be included in any redistribution
***************************************************************************/
 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
 
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
 
Adafruit_BMP280 bme; // I2C
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
 
void setup() {
Serial.begin(115200);
Serial.println(F("BMP280 test"));
 // Error Sensor not found. Then you need to find the correct I2C Adresse . Help here: https://www.circuitschools.com/interfacing-16x2-lcd-module-with-esp32-with-and-without-i2c/
if (!bme.begin(0x76)) { 
Serial.println("Could not find a valid BMP280 sensor, check wiring!");
while (1);
}

  /* Default settings from datasheet. */
  bme.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}
 
void loop() {
Serial.print("Temperature = ");
Serial.print(bme.readTemperature());
Serial.println(" *C");
 
Serial.print("Pressure = ");
Serial.print(bme.readPressure()/100);
Serial.println(" hPa");
 
Serial.print("Approx altitude = ");
Serial.print(bme.readAltitude(1005.4)); // this should be adjusted to your local forcase
Serial.println(" m");
 
Serial.println();
delay(2000);
}
