#include <Arduino.h>
#include "BTS7960.h"

void BTS_init(int RPWM, int LPWM)
{
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void BTS_drive(int RPWM, int LPWM, int speed_in_pwm)
{
  speed_in_pwm = constrain(speed_in_pwm, -255, 255);

  if (speed_in_pwm > 0)
  {
    // forward
    analogWrite(RPWM, speed_in_pwm);
    analogWrite(LPWM, 0);
  }
  else if (speed_in_pwm < 0)
  {
    // backward
    analogWrite(RPWM, 0);
    analogWrite(LPWM, -speed_in_pwm);
  }
  else
  {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }
}
