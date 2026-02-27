int ENA = 13;
int ENB = 32;
int in1 = 27;
int in2 = 26;
int in3 = 25;
int in4 = 33;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // move foward
  analogWrite(ENA, 255); //Enable motor A
  analogWrite(ENB, 255); //Enable motor B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);

  // STOP
  analogWrite(ENA, 0); //Enable motor A
  analogWrite(ENB, 0); //Enable motor B
  delay(2000);

  // move backward
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

    // STOP
  analogWrite(ENA, 0); //Enable motor A
  analogWrite(ENB, 0); //Enable motor B
  delay(2000);
}
