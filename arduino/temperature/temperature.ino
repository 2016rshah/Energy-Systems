#include <OneWire.h>
#include <LiquidCrystal.h>=
OneWire ds(13);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(void) {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Temperature: ");
}

void loop(void) {
  int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  ds.reset_search();
  if ( !ds.search(addr)) {
      Serial.print("No more addresses.\n");
      ds.reset_search();
      return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);

  delay(1000);

  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); 
  for ( i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }
  
  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;
  if (SignBit)
  {
    TReading = (TReading ^ 0xffff) + 1;
  }
  Tc_100 = (6 * TReading) + TReading / 4; 

  Whole = Tc_100 / 100; 
  Fract = Tc_100 % 100;
  
  lcd.setCursor(0, 1);
  
  if (SignBit)
  {
     lcd.print("-");
  }
  lcd.print(Whole);
  lcd.print(".");
  if (Fract < 10)
  {
     lcd.print("0");
  }
  lcd.print(Fract);
}
