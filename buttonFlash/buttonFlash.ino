// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton2 = 2;
int pushButton3 = 3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState2 = digitalRead(pushButton2); //if buttonState2 = 0, not pressed. Else: pressed
  int buttonState3 = digitalRead(pushButton3);
  
  if(buttonState2 == 1){
    Serial.println("First button pressed");
     fastFlash();
  }
  if(buttonState3 == 1){
    Serial.println("Second button pressed");
     slowFlash(); 
  }
  delay(1);
}

void fastFlash(){
  digitalWrite(13, HIGH); 
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
void slowFlash(){
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(500);
}

