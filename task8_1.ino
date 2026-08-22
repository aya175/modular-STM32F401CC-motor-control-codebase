#include "pins.h"
#include "L298N.h"
#include "Cytron.h"
#include "BTS7960.h"

void demo_L298N();
void demo_Cytron();
void demo_BTS7960();

void setup()
{
  Serial.begin(115200);

  L298N_init(L298N_IN1, L298N_IN2, L298N_ENA);
  Cytron_init(CYTRON_DIR, CYTRON_PWM);
  BTS_init(BTS_RPWM, BTS_LPWM);

  Serial.println("Motor drivers ready - starting demo");
}

void loop()
{
  demo_L298N();
  demo_Cytron();
  demo_BTS7960();

  delay(2000); // pause,then repeat forever
}

void demo_L298N()
{
  Serial.println("L298N: forward");
  L298N_drive(L298N_IN1, L298N_IN2, L298N_ENA, 200);
  delay(1500);

  Serial.println("L298N: backward");
  L298N_drive(L298N_IN1, L298N_IN2, L298N_ENA, -200);
  delay(1500);

  Serial.println("L298N: stop");
  L298N_drive(L298N_IN1, L298N_IN2, L298N_ENA, 0);
  delay(500);
}

void demo_Cytron()
{
  Serial.println("Cytron: forward");
  Cytron_drive(CYTRON_DIR, CYTRON_PWM, 200);
  delay(1500);

  Serial.println("Cytron: backward");
  Cytron_drive(CYTRON_DIR, CYTRON_PWM, -200);
  delay(1500);

  Serial.println("Cytron: stop");
  Cytron_drive(CYTRON_DIR, CYTRON_PWM, 0);
  delay(500);
}

void demo_BTS7960()
{
  Serial.println("BTS7960: forward");
  BTS_drive(BTS_RPWM, BTS_LPWM, 200);
  delay(1500);

  Serial.println("BTS7960: backward");
  BTS_drive(BTS_RPWM, BTS_LPWM, -200);
  delay(1500);

  Serial.println("BTS7960: stop");
  BTS_drive(BTS_RPWM, BTS_LPWM, 0);
  delay(500);
}
