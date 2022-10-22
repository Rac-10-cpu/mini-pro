#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  Serial.begin (9600);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Detecting i2c values");
  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  lcd.print("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      lcd.setCursor(0,0);
      lcd.print("Found Address");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("(0x");
      lcd.print(i,HEX);
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
 // Serial.println ("Done.");
 // Serial.print ("Found ");
 // Serial.print (count, DEC);
//  Serial.println (" device(s).");
}  // end of setup

void loop() {}
