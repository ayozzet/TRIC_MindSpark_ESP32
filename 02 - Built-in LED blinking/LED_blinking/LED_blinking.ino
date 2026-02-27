int r = 4;
int g = 5;
int b = 6;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(500);
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(500);
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(500);
}
