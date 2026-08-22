Modular motor control for three driver types (L298N, Cytron MD10A, BTS7960)
on the STM32F401CC (Black Pill), written for Arduino IDE.

## Repo layout

 required deliverable, plain C-style functions matching the
  exact signatures from the task sheet.
 OOP: same behavior, wrapped in a `MotorDriver` base
  class with `L298N_Motor`, `CytronMD10A_Motor`, `BTS7960_Motor` children.

## How direction + speed work

All `_drive()` functions take a single signed `speed_in_pwm`:
- `> 0` -> forward
- `< 0` -> backward
- `0`   -> stop

This keeps the API to one call per motor instead of separate
forward/backward functions.

## Pin choices (STM32F401CC)

| Driver     | Signal | Pin | Notes                     |
|------------|--------|-----|----------------------------|
| L298N      | IN1    | PA0 | direction                  |
| L298N      | IN2    | PA1 | direction                  |
| L298N      | ENA    | PA2 | PWM (TIM2/TIM5 channel)    |
| Cytron     | DIR    | PA3 | direction                  |
| Cytron     | PWM    | PA6 | PWM (TIM3 channel)         |
| BTS7960    | RPWM   | PA7 | forward PWM (TIM3 channel) |
| BTS7960    | LPWM   | PB0 | backward PWM (TIM3 channel)|

