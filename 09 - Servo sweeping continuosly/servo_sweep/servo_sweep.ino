#include <ESP32Servo.h>

Servo myservo;
int pos = 0;
int servoPin = 17;
int btn = 4;

void setup() {
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);
	myservo.attach(servoPin, 1000, 2000);
	pinMode(btn, INPUT)
}

void loop() {
	int state = digitalRead(btn);
	if (state == 1) {
		myservo.write(0);
		delay(500);
	} else {
		myservo.write(180);
		delay(500);
	}
}
