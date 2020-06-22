#include <Arduino.h>
#include <Servo.h>
#include "joystick.h"

#define Xpin A0
#define Ypin A1
#define ButtonPin 6
int angleX = 90;
int angleY = 90;
int angleY1 = 90;
int count = 0;

Joystick joy(Xpin, Ypin);
Servo horizServo;
Servo vertServo1;
Servo vertServo2;

void setup()
{
  Serial.begin(9600);
  joy.begin();
  pinMode(ButtonPin, INPUT);
  horizServo.attach(9);
  vertServo1.attach(11);
  vertServo2.attach(10);
}

void loop()
{
  // Serial.println("y:");
  // Serial.println(joy.getValueY());
  // Serial.println("x:");
  // Serial.println(joy.getValueX());

  // first servo
  if (joy.getValueX() > 503)
  {
    angleX += joy.positiveDirectonX();
    horizServo.write(angleX);

    if (angleX > 180)
    {
      angleX = 180;
    }

    delay(20);
  }
  else if (joy.getValueX() < 483)
  {
    angleX -= joy.negativeDirectonX();
    horizServo.write(angleX);

    if (angleX < 0)
    {
      angleX = 0;
    }
  }

  if (digitalRead(ButtonPin) == LOW)
  {
    delay(300);
    count++;
  }

  // second servo
  if (joy.getValueY() > 530)
  {

    switch (count)
    {
    case 0:
      angleY = vertServo1.read();
      angleY1 = vertServo2.read();

      angleY += joy.positiveDirectonY();
      angleY1 += joy.positiveDirectonY();

      vertServo1.write(angleY);
      vertServo2.write(angleY1);
      break;
    case 1:
      angleY = vertServo1.read();
      angleY += joy.positiveDirectonY();
      vertServo1.write(angleY);
      break;
    case 2:
      angleY1 = vertServo2.read();
      angleY1 += joy.positiveDirectonY();
      vertServo2.write(angleY1);
      break;
    }

    if (count > 2)
    {
      count = 0;
    }

    if (angleY > 180)
    {
      angleY = 180;
    }

    delay(20);
  }
  else if (joy.getValueY() < 510)
  {

    // angleY -= joy.negativeDirectonY();

    switch (count)
    {
    case 0:
      angleY = vertServo1.read();
      angleY1 = vertServo2.read();

      angleY -= joy.negativeDirectonY();
      angleY1 -= joy.negativeDirectonY();

      vertServo1.write(angleY);
      vertServo2.write(angleY1);
      break;
    case 1:
      angleY = vertServo1.read();
      angleY -= joy.negativeDirectonY();
      vertServo1.write(angleY);
      break;
    case 2:
      angleY1 = vertServo2.read();
      angleY1 -= joy.negativeDirectonY();
      vertServo2.write(angleY1);
      break;
    }

    if (count > 2)
    {
      count = 0;
    }

    if (angleY < 0)
    {
      angleY = 0;
    }

    delay(20);
  }
}