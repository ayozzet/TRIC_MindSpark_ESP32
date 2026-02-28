#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define LED_PIN 2   // Change if your board uses different pin

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Dabble.begin("MAX_LED_Control");
}

void loop()
{
  Dabble.processInput();

  // Button A → ON
  if (GamePad.isCirclePressed())   // Button A in Dabble layout
  {
    digitalWrite(LED_PIN, HIGH);
  }

  // Button B → OFF
  if (GamePad.isCrossPressed())    // Button B in Dabble layout
  {
    digitalWrite(LED_PIN, LOW);
  }
}
