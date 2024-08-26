#include <Arduino.h>
#ifndef MAIN_H
#define MAIN_H

struct Joystick
{
    float x;
    float y;
};

struct Remote
{
    Joystick left;
    Joystick right;
    bool left_button;
    bool right_button;
};

struct PID
{
    float p;
    float i;
    float d;
};

extern Remote remote_data;
extern PID pid_data;

#endif