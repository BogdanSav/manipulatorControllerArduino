#include <Arduino.h>
#include <Servo.h>
#include "joystick.h"

#define Xpin A0
#define Ypin A1
int angleX = 90;
Joystick joy(Xpin, Ypin);
Servo servo1;

void setup()
{
  Serial.begin(9600);
  joy.begin();
  servo1.attach(9);
  servo1.write(angleX);
}

void loop()
{
  

  // Serial.println(joy.getValueX());
  if (joy.getValueX() > 503)
  {
    angleX+=joy.positiveDirectonX();
    servo1.write(angleX);
    // Serial.println(joy.positiveDirectonX());
    if(angleX<0)
    {
      angleX =0;
    }
    delay(20);
  }
  else if (joy.getValueX() < 483)
  {
    angleX-=joy.negativeDirectonX();
    servo1.write(angleX);
    // Serial.println(joy.negativeDirectonX());
    if(angleX>180)
    {
      angleX=180;
    }
    delay(20);
  }
  if(joy.getValueY()>0)
  {
    
  }
 
}