#ifndef PINS_H
#define PINS_H

//L298N pins
#define L298N_IN1   PA0 // direction
#define L298N_IN2   PA1 // direction
#define L298N_ENA   PA2 // PWM speed (TIM2/TIM5 channel)

//Cytron MD10A pins
#define CYTRON_DIR  PA3 // direction
#define CYTRON_PWM  PA6 // PWM speed (TIM3 channel)

//BTS7960 pins
#define BTS_RPWM    PA7 // forward PWM (TIM3 channel)
#define BTS_LPWM    PB0 // backward PWM (TIM3 channel)

#endif
