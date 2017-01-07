# Arduino PWM Flight

This project allows your Arduino to act as a radio receiver/transmitter. It will output PWM just like a normal RC receiver. 

### Controls
To control the flight joysticks, open the Arduino Serial Monitor and type a letter and press Enter.<p>
Throttle Up - W<br>
Throttle Down - S<br>
Roll Up - D<br>
Roll Down - A<br>
Pitch Up - Q<br>
Pitch Down - Z<br>
Yaw Up - E<br>
Yaw Down - C<br>
Flight Mode Change - 1, 2, or 3<br>
Turn Off Everything - L<br>

### Your Config
You should only need to change a couple things to get this working for you. Change the pin value to a PWM output that is connected to your device.

```bash
int ThrottlePin = 9;
int RollPin = 11;
int PitchPin = 5;
int YawPin = 3;
int FlightModePin = 6;
```
