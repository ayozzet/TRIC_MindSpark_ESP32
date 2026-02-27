#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

/* ================= MOTOR PIN CONFIG ================= */

// Right Motor
#define EN_R   26
#define IN1_R  12
#define IN2_R  13

// Left Motor
#define EN_L   25
#define IN1_L  27
#define IN2_L  14

#define MAX_SPEED 255

/* ================= PWM CONFIG ================= */

const int PWM_FREQ = 1000;
const int PWM_RES  = 8;
const int CH_R = 4;
const int CH_L = 5;

/* ================= MOTOR CONTROL ================= */

void setMotor(int rightSpeed, int leftSpeed)
{
  // ----- Right Motor -----
  if (rightSpeed > 0)
  {
    digitalWrite(IN1_R, HIGH);
    digitalWrite(IN2_R, LOW);
  }
  else if (rightSpeed < 0)
  {
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, HIGH);
  }
  else
  {
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, LOW);
  }

  // ----- Left Motor -----
  if (leftSpeed > 0)
  {
    digitalWrite(IN1_L, HIGH);
    digitalWrite(IN2_L, LOW);
  }
  else if (leftSpeed < 0)
  {
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, HIGH);
  }
  else
  {
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, LOW);
  }

  ledcWrite(CH_R, abs(rightSpeed));
  ledcWrite(CH_L, abs(leftSpeed));
}

/* ================= SETUP ================= */

void setup()
{
  // Motor pins
  pinMode(IN1_R, OUTPUT);
  pinMode(IN2_R, OUTPUT);
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);

  // PWM setup
  ledcSetup(CH_R, PWM_FREQ, PWM_RES);
  ledcSetup(CH_L, PWM_FREQ, PWM_RES);
  ledcAttachPin(EN_R, CH_R);
  ledcAttachPin(EN_L, CH_L);

  setMotor(0, 0);  // Safety stop

  Dabble.begin("ESP32_Robot_aqmal");
}

/* ================= MAIN LOOP ================= */

void loop()
{
  Dabble.processInput();

  int rightSpeed = 0;
  int leftSpeed  = 0;

  if (GamePad.isUpPressed())
  {
    rightSpeed = MAX_SPEED;
    leftSpeed  = MAX_SPEED;
  }
  else if (GamePad.isDownPressed())
  {
    rightSpeed = -MAX_SPEED;
    leftSpeed  = -MAX_SPEED;
  }
  else if (GamePad.isLeftPressed())
  {
    rightSpeed = MAX_SPEED;
    leftSpeed  = -MAX_SPEED;
  }
  else if (GamePad.isRightPressed())
  {
    rightSpeed = -MAX_SPEED;
    leftSpeed  = MAX_SPEED;
  }

  setMotor(rightSpeed, leftSpeed);
}