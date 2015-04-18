#include <EEPROM.h>
int address = 0;

void setup() {
  Serial.begin(9600);
}

void loop(){
  
  Serial.print(address);
  Serial.print(", ");
  Serial.print(EEPROM.read(address));
  Serial.print(", ");
  Serial.println(EEPROM.read(address+512));
  
  
  delay(10);
  address++;
  
  
  if(address == 512){ while(1) {} }  
}
