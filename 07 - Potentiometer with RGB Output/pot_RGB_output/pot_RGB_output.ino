int pot = 4;

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(115200);
}

void loop() {
  int pot = analogRead(pot);
  Serial.println(pot);
  delay(100);
}
