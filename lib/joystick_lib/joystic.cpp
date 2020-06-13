#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick(byte pinX, byte pinY)
{
    this->pinX = pinX;
    this->pinY = pinY;
};
void Joystick::begin()
{
    pinMode(pinY, INPUT);
    pinMode(pinX, INPUT);
};
int Joystick::getValueX()
{
    valueX = analogRead(pinX);
    return valueX;
};
int Joystick::getValueY()
{
    valueY = analogRead(pinY);
    return valueY;
};
int Joystick::positiveDirectonX()
{
    int positiveDirecton = map(valueX, 513, 1023, 1, 3);

    switch (positiveDirecton)
    {
        case 1: return positiveDirecton; break;
        case 2: return positiveDirecton; break;
        case 3: return positiveDirecton; break;
        // case 4: return positiveDirecton; break;
        // case 5: return positiveDirecton; break;
    }
};
int Joystick::negativeDirectonX()
{
    int positiveDirecton = map(valueX, 0, 473, 3, 1);

    switch (positiveDirecton)
    {
        case 1: return positiveDirecton; break;
        case 2: return positiveDirecton; break;
        case 3: return positiveDirecton; break;
        // case 4: return positiveDirecton; break;
        // case 5: return positiveDirecton; break;
    }
};
int Joystick::positiveDirectonY()
{
    int positiveDirecton = map(valueY, 540, 1023, 1, 3);

    switch (positiveDirecton)
    {
        case 1: return positiveDirecton; break;
        case 2: return positiveDirecton; break;
        case 3: return positiveDirecton; break;
        // case 4: return positiveDirecton; break;
        // case 5: return positiveDirecton; break;
    }
};
int Joystick::negativeDirectonY()
{
    int positiveDirecton = map(valueY, 0, 500, 3, 1);

    switch (positiveDirecton)
    {
        case 1: return positiveDirecton; break;
        case 2: return positiveDirecton; break;
        case 3: return positiveDirecton; break;
        // case 4: return positiveDirecton; break;
        // case 5: return positiveDirecton; break;
    }
};
