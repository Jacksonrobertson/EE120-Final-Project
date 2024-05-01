// EE120 Final Project
// Temperature & Remote Controlled Fan
// Jackson Robertson & Ashton Hayes
// License: MIT
// Version 1.1

#include <LiquidCrystal.h>
#include <IRremote.hpp>
#include <DHT11.h>

#define ir_pin 1
#define dht_pin 13

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT11 dht11(dht_pin);

void setup() {
lcd.begin(16, 2);
Serial.begin(9600);
lcd.print("Fan 1.0");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
}

void loop() {
readtemp();
}





int readtemp() {
      int temperatureC = dht11.readTemperature(); 
    int temperatureF = ((9/5)*temperatureC+32);
      if (temperatureC != DHT11::ERROR_CHECKSUM && temperatureC != DHT11::ERROR_TIMEOUT) {
        lcd.clear();
        lcd.print("Temp: ");
        lcd.print(temperatureF);
        lcd.print("\337F");
    } else {
        // Print error message based on the error code.
        Serial.println(DHT11::getErrorString(temperatureC));
    }
    delay(50);
}

