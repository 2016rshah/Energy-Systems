
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  dot();
  dot();
  dot();
  dash();
  dash();
  dash();
}
void dot(){
  digitalWrite(13, HIGH); 
  delay(500);
  digitalWrite(13, LOW);
  delay(1000);
}
void dash(){
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
