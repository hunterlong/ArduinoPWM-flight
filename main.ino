#include <Servo.h> 

Servo ThrottleServo;
Servo RollServo;
Servo PitchServo;
Servo YawServo;
Servo FlightModeServo;

// CHANGE PIN VALUES
int ThrottlePin = 9;
int RollPin = 11;
int PitchPin = 5;
int YawPin = 3;
int FlightModePin = 6;




int throttle = 1000; int tothrottle = 1000;
int roll = 1500; int toroll = 1500;
int pitch = 1500; int topitch = 1500;
int yaw = 1500; int toyaw = 1500;
int flightmode = 1000;
bool started = false;

void setup() {
Serial.begin(9600);
  ThrottleServo.attach(ThrottlePin);
  RollServo.attach(RollPin);
  PitchServo.attach(PitchPin);
  YawServo.attach(YawPin);
  FlightModeServo.attach(FlightModePin);
  
  ThrottleServo.writeMicroseconds(1000);
  RollServo.writeMicroseconds(1500);
  PitchServo.writeMicroseconds(1500);
  YawServo.writeMicroseconds(1500);
  FlightModeServo.writeMicroseconds(1000);
  
  Serial.println("Ready");

}

int i = 0;
void loop() {
  i++;

  if ( Serial.available()) {
    char ch = Serial.read();

    switch(ch) {
      case '1':
       flightmode=1000;
        break;
      case '2':
       flightmode=1500;
        break;
      case '3':
       flightmode=2000;
        break;    
      case 'x':
        tothrottle = 1000;
        started=true;
        Serial.println("Starting!");
        break;  
      case 'v':
        started=false;
        Serial.println("Stopping!");
        break;   
      case 'w':
        tothrottle = throttle + 100;
        break;
      case 's':
        tothrottle = throttle - 100;
        break;  
      case 'd':
        toroll = roll + 100;
        break;
      case 'a':
        toroll = roll - 100;
        break;    
      case 'q':
        topitch = pitch + 100;
        break;
      case 'z':
        topitch = pitch - 100;
        break;    
      case 'e':
        toyaw = yaw + 100;
        break;   
      case 'c':
        toyaw = yaw - 100;
        break;         
      case 'f':
        tothrottle = 2000;
        toroll = 2000;
        break;    
      case 'l':
        tothrottle = 1000;
        toroll = 1500;
        topitch = 1500;
        toyaw = 1500;
        flightmode = 1000;
        break;   
      case 'o':
        digitalWrite(6,HIGH);
        break;     
      case 'p':
        digitalWrite(6,LOW);
        break;   
    }
  }

if (i % 10 == 0){

  if (tothrottle > throttle){
    throttle = throttle + 5;
  } else if (tothrottle < throttle){
    throttle = throttle - 5;
  }
  if (throttle >= 2000) throttle = 2000;
  if (throttle <= 1000) throttle = 1000;

  if (toroll > roll){
    roll = roll + 10;
  } else if (toroll < roll){
    roll = roll - 10;
  }
  if (roll >= 2000) roll = 2000;
  if (roll <= 1000) roll = 1000;

  if (topitch > pitch){
    pitch = pitch + 10;
  } else if (topitch < pitch){
    pitch = pitch - 10;
  }
  if (pitch >= 2000) pitch = 2000;
  if (pitch <= 1000) pitch = 1000;

  if (toyaw > yaw){
    yaw = yaw + 10;
  } else if (toyaw < yaw){
    yaw = yaw - 10;
  }
  if (yaw >= 2000) yaw = 2000;
  if (yaw <= 1000) yaw = 1000;

  ThrottleServo.writeMicroseconds(throttle);
  RollServo.writeMicroseconds(roll);
  PitchServo.writeMicroseconds(pitch);
  YawServo.writeMicroseconds(yaw);
  FlightModeServo.writeMicroseconds(flightmode);

  Serial.print("Throttle: ");
    Serial.print(throttle);
  Serial.print(" Pitch: ");
    Serial.print(pitch);
  Serial.print(" Roll: ");
    Serial.print(roll);
  Serial.print(" Yaw: ");
    Serial.print(yaw);      
  Serial.println("");
  
}



}









