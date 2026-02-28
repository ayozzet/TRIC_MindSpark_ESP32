int pot = 9;

void setup() {
  Serial.begin (115200);
  pinMode(pot, INPUT);
}

void loop() {
  int potVal = analogRead(pot);
  Serial.println(potVal);  
  delay(50);
}
