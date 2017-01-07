# Arduino PWM Flight

This project allows your Arduino to act as a radio receiver for your quadcopters flight controller. It will output PWM just like a normal RC receiver. This arduino code doesn't communicate directly to your ESC, but should replace your RC receiver that went into your flight controller. On my quadcopter, I'm using CC3D as a flight controller. Your Arduino board must be connected to the same curcuit as your flight controller. 

[![arduquod3.jpg](https://s27.postimg.org/d7frgj1z7/arduquod3.jpg)](https://postimg.org/image/o70ys4se7/)

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

### OpenPilot Configs
All you need to do is match the Channel number with the pin you used for the connections.
[![quadimg.jpg](https://s27.postimg.org/z8o6ej9ir/quadimg.jpg)](https://postimg.org/image/dm95xiay7/)
[![quadimg2.jpg](https://s30.postimg.org/ns7c1i39t/quadimg2.jpg)](https://postimg.org/image/duwb8fvnx/)
Min and Max number should stay the same, Min=1000, Max=2000. Throttle Starts at 1000, meaning 0. Roll, Pitch and Yaw start in the middle at 1500. Flight Mode starts a 1000 for level 1, 1500 level 2, and 2000 for level 3.
