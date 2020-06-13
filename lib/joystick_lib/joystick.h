#ifndef JOYSTICK_H
#define JOYSTICK_H
class Joystick
{
private:
    int pinY;
    int pinX;
    int valueX;
    int valueY;
    
public:
    Joystick(byte pinX, byte pinY);
    void begin();
    int getValueX();
    int getValueY();
    int positiveDirectonX();
    int positiveDirectonY();
    int negativeDirectonX();
    int negativeDirectonY();


};

#endif JOYSTICK_H