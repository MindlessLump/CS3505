/*
 * Naoki Tominaga
 * CS 3505
 * Assignment A2
 */

#include <iostream>
#include <math.h>
#include "Spiral.h"

using namespace std;

Spiral::Spiral(double centerX, double centerY, double rad0){
    radius = rad0;
    spiralAngle = 90;
    center_X = centerX;
    center_Y = centerY;
    X = centerX + cos(spiralAngle * M_PI / 180) * radius;
    Y = centerY + sin(spiralAngle * M_PI / 180) * radius;
}

double Spiral::get_text_x(){
    return X;
}

double Spiral::get_text_y(){
    return Y;
}

double Spiral::get_spiral_angle(){
    return spiralAngle;
}

double Spiral::get_text_angle(){
    return (spiralAngle - 90);
}

Spiral& Spiral::operator++(){
    radius = radius + 1;
    spiralAngle -= 10.0;
    X = center_X + cos(spiralAngle * M_PI / 180) * radius;
    Y = center_Y + sin(spiralAngle * M_PI / 180) * radius;
    return *this;
}

Spiral Spiral::operator++(int){
    Spiral temp = *this;
    ++(*this);
    return temp;
};

ostream& operator<<(ostream& output, Spiral spiral){
    output << "The spiral angle is " << spiral.spiralAngle << " degrees and the radius is " << spiral.radius;
    return output;
}
