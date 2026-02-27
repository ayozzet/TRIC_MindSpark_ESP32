int pot = 4;
int r = 5;
int g = 6;
int b = 7;

void setup() {
  pinMode(pot, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  int pot = analogRead(pot);
  if (pot < 1500) {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  }
  if ((pot >= 1500) && (pot < 3000)) {
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  } else {
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
  }
}
