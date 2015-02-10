int CW1 = 200;
int CCW = 100;
int CW2 = 300;
boolean gate1 = false;
boolean gate2 = false;
boolean gate3 = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if(!gate1){
    if(sensorValue == CW1){
      gate1 = true;
      Serial.println("IT WORKED HURRAH!");
    }
  }
  if(gate1 && !gate2){
    if(sensorValue == CCW){
      gate2 = true;
      Serial.println("WOOOHOOO IT WORKED AGAIN!");
    }  
  }
  if(gate1 && gate2 && !gate3){
    if(sensorValue == CW2){
      gate3 = true;
      Serial.println("FINISHED IT PARTY!!!!!!!");
    }  
  }
  if(gate1 && gate2 && gate3){
    turnOnLight();
  }
  // print out the value you read:
  //Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
void turnOnLight(){
    digitalWrite(13, HIGH);
}
