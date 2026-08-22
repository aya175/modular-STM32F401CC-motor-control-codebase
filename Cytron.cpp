#include <Arduino.h>
#include "Cytron.h"

void Cytron_init(int DIR, int PWM)
{
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);

  digitalWrite(DIR, LOW);
  analogWrite(PWM, 0);
}

// speed_in_pwm
void Cytron_drive(int DIR, int PWM, int speed_in_pwm)
{
  speed_in_pwm = constrain(speed_in_pwm, -255, 255);

  if (speed_in_pwm >= 0)
  {
    digitalWrite(DIR, HIGH); // forward
    analogWrite(PWM, speed_in_pwm);
  }
  else
  {
    digitalWrite(DIR, LOW); // backward
    analogWrite(PWM, -speed_in_pwm);
  }
}
