
// include the library code:
#include <LiquidCrystal.h>
#include <EEPROM.h>
int address = 0;
float v1 = 0.00;
float v2 = 0.00;
float amp = 0.00;
int volt1 = 0;
int volt2 = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  volt1 = analogRead(A0);
  volt2 = analogRead(A1);
  
  lcd.setCursor(0, 0);
  v1 = volt1 * 0.00489 * ((3.3+4.7)/3.3);
  lcd.print("V: ");
  lcd.print(v1);
  
  lcd.setCursor(0, 1);
  v2 = volt2 * 0.00489 * ((3.3+4.7)/3.3);
  amp = (v2-v1)*(-10);
  lcd.print("mA: ");
  lcd.print(amp);
  
  //store in EEPROM
  EEPROM.write(address, byte(v1));
  EEPROM.write(address+512, byte(amp));
  
  //print to console to monitor
  Serial.print(address);
  Serial.print(", ");
  Serial.print(byte(v1));
  Serial.print(", ");
  Serial.println(byte(amp));
  
  
  //increment storage address and wait a bit before measuring again
  address++;
  delay(500);
  
  //infinite loop that does nothing when you run out of memory
  if(address==512){ while(1){} }
}

