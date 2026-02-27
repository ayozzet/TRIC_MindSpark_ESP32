int btn = 4;

void setup() {
  pinMode(btn, INPUT);
  Serial.begin(115200);
}

void loop() {
  int state = digitalRead(btn);
  Serial.println(state);
  delay(100);
}
