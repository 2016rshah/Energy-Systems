int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  photocellReading = analogRead(photocellPin);  
  if(photocellReading < 800){
    makeDark();  
  }  
  else{
    makeBright();  
  }
  delay(1000);
}


void makeBright(){
    analogWrite(led, 200);  
}
void makeDark(){
    analogWrite(led, 55);  
}
