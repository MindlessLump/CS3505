//Michael Swisher CS3505
//A2: Classes and Facades
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include "Spiral.h"

Spiral::Spiral(double x, double y, double radiusSpir)
{
    centerX = x;
    centerY = y;
    if(radiusSpir < 50) radiusSpir = 50;
    radius = radiusSpir;
    angle = 90;
    tAngle = (angle - 90) / 180 * M_PI;
    sAngle = angle / 180 * M_PI;
    i = 0;
    x = centerX + cos(sAngle) * (i + radius);
    y = centerY + sin(sAngle) * (i + radius);
}
double Spiral::get_text_x()
{
    return x;
}
double Spiral::get_text_y()
{
    return y;
}
double Spiral::get_spiral_angle()
{
    return sAngle;
}
double Spiral::get_text_angle()
{
    return tAngle;
}

Spiral Spiral::operator++()
{
    i+= 0.75;
    tAngle = (angle - 90) / 180 * M_PI;
    sAngle =(angle / 180) * M_PI;
    x = centerX + cos(sAngle) * (i + radius);
    y = centerY + sin(sAngle) * (i + radius);
    angle -=10.0;
    return *this;
}
Spiral Spiral::operator++(int)
{
    i+= 0.75;
    tAngle = (angle - 90) / 180 * M_PI;
    sAngle =(angle / 180) * M_PI;
    x = centerX + cos(sAngle) * (i + radius);
    y = centerY + sin(sAngle) * (i + radius);
    angle -=10.0;
    return *this;
}
std::ostream& operator<< (std::ostream& os, const Spiral& spir)
{
    os << "Angle: " <<  spir.sAngle << "and Radius: " << (spir.i + spir.radius);
    return os;
}
