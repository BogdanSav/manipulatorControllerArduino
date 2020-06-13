#include <Arduino.h>
#include <Servo.h>
#include "joystick.h"

#define Xpin A0
#define Ypin A1
int angleX = 0;
int angleY = 0;
Joystick joy(Xpin, Ypin);
Servo servo1;
Servo servo2;

void setup()
{
  Serial.begin(9600);
  joy.begin();
  servo1.attach(9);
  servo2.attach(11);
  
  // angleX = servo1.read();
  // angleY = servo2.read();

  // servo1.write(angleX);
  // servo2.write(angleY);
}

void loop()
{
  Serial.println("y:");
  Serial.println(joy.getValueY());
  Serial.println("x:");
  Serial.println(joy.getValueX());
  // first servo
  if (joy.getValueX() > 503)
  {
    angleX += joy.positiveDirectonX();
    servo1.write(angleX);

    if (angleX > 180)
    {
      angleX = 180;
    }

    delay(20);
  }
  else if (joy.getValueX() < 483)
  {
    angleX -= joy.negativeDirectonX();
    servo1.write(angleX);

    if (angleX < 0)
    {
      angleX = 0;
    }
  }
  // second servo
  if (joy.getValueY() > 530)
  {
    angleY += joy.positiveDirectonY();
    servo2.write(angleY);
    if (angleY > 180)
    {
      angleY = 180;
    }
    delay(20);
  }
  else if (joy.getValueY() < 510)
  {

    angleY -= joy.negativeDirectonY();
    servo2.write(angleY);

    if (angleY < 0)
    {
      angleY = 0;
    }

    delay(20);
  }
}