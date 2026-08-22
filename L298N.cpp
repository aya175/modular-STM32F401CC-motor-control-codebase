#include <Arduino.h>
#include "L298N.h"

// Call once in setup() for each L298N channel i'm use
void L298N_init(int IN1, int IN2, int ENA)
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // start in a safe "stopped" state
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

// speed_in_pwm
void L298N_drive(int IN1, int IN2, int ENA, int speed_in_pwm)
{
  speed_in_pwm = constrain(speed_in_pwm, -255, 255); // a safe range

  if (speed_in_pwm > 0)
  {
    // forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed_in_pwm);
  }
  else if (speed_in_pwm < 0)
  {
    // backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, -speed_in_pwm); // PWM needs a +ve number
  }
  else
  {
    // stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  }
}
