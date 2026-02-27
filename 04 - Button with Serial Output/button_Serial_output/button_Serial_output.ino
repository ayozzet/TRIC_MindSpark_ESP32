int btn = 4;
int r = 5;
int g = 6;

void setup() {
  pinMode(btn, INPUT);
  pinMode(r, OUTPUT);
}

void loop() {
  int state = digitalRead(btn);
  if (state == 1) {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
  } else {
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
  }
}
