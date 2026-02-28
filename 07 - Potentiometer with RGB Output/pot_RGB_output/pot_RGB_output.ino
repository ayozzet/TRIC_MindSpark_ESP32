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
  int potVal = analogRead(pot);
  if (potVal <1000){
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  }
  if ((potVal >= 1000) && (potVal < 2000)){
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  }
  if ((potVal >= 2000) && (potVal < 3000)){
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  }
  else{
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
  }
  
}
