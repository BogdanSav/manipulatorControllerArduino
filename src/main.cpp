#include <Arduino.h>
#include <Servo.h>
#include "joystick.h"

//defines
#define Xpin A5
#define Ypin A4
#define ButtonPin A3
#define buttonOpen A2
#define buttonClose A1

//functions
void yAxisPos();
void yAxisNeg();

//variables
int angleX = 90;
int angleY = 90;
int angleY1 = 90;
int captorAngle = 90;
int count = 0;

//classes
Joystick joy(Xpin, Ypin);
Servo horizServo;
Servo vertServo1;
Servo vertServo2;
Servo captorServo;

void setup()
{
  Serial.begin(9600);
  joy.begin();

  pinMode(ButtonPin, INPUT);
  pinMode(buttonClose, INPUT);
  pinMode(buttonOpen, INPUT);

  horizServo.attach(9);
  vertServo1.attach(11);
  vertServo2.attach(10);
  captorServo.attach(5);
}

void loop()
{

  //horizontal servo
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
    delay(20);
  }
  // joystick button
  if (digitalRead(ButtonPin) == LOW)
  {
    delay(300);
    count++;
  }

  // vertical servos
  if (joy.getValueY() > 530)
  {

    yAxisPos();

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

    yAxisNeg();

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

  if (digitalRead(buttonOpen) == HIGH)
  {
    captorAngle += 2;
    captorServo.write(captorAngle);
    if (captorAngle > 180)
    {
      captorAngle = 180;
    }
    delay(20);
  }
  else if (digitalRead(buttonClose) == HIGH)
  {
    captorAngle -= 2;
    captorServo.write(captorAngle);
    if (captorAngle < 90)
    {
      captorAngle = 90;
    }
   delay(20);
  }
  else if (digitalRead(buttonClose) && digitalRead(buttonOpen) == HIGH)
  {
    delay(20);
  }
}

// functions
void yAxisPos()
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
}

void yAxisNeg()
{
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
}