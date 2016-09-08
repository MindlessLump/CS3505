/*
 * Erik Martin
 * CS3505
 * A2 - Classes and Facades
 */

#include "Spiral.h"
#include <math.h>
#include <iostream>
using namespace std;

// Constructs a spiral with the given center and starting radius
// Begins with the text at the 12-o-clock position
Spiral::Spiral(double centerX, double centerY, float startRad) {
    _centerX = centerX;
    _centerY = centerY;
    radius = startRad;

    if (radius < 10) {
        radius = 10;
    }

    angle2 = 90; // Start at the 12-o-clock position
    rad1 = (angle2 - 90) / 180 * M_PI; // Angle of letter on page
    rad2 = angle2 / 180 * M_PI; // How far around circle you are

    // x = center + cos(rad2) * radius
    // y = center + sin(rad2) * radius
    x = _centerX + cos(rad2) * radius;
    y = _centerY + sin(rad2) * radius;
}

// Returns the current x-position of the text spiral
double Spiral::get_text_x() {
    return (double)x;
}

// Returns the current y-position of the text spiral
double Spiral::get_text_y() {
    return (double)y;
}

// Returns the current spiral angle (rad2) of the text spiral in degrees
double Spiral::get_spiral_angle() {
    return (double)(rad2 * 180 / M_PI);
}

// Returns the current text angle (rad1) of the text spiral in degrees
double Spiral::get_text_angle() {
    return (double)(rad1 * 180 / M_PI);
}

// Returns cos(rad1) for the SetTextMatrix function of HPDF
double Spiral::get_text_cosine() {
    return (double) cos(rad1);
}

// Returns sin(rad1) for the SetTextMatrix function of HPDF
double Spiral::get_text_sine() {
    return (double) sin(rad1);
}

// Overrides the prefix ++ operator
Spiral& Spiral::operator++() {
    // Rotate position and slightly increase radius
    angle2 -= 7.5;
    radius += 0.8;
    // Update dependent variables accordingly
    rad1 = (angle2 - 90) / 180 * M_PI;
    rad2 = angle2 / 180 * M_PI;
    x = _centerX + cos(rad2) * radius;
    y = _centerY + sin(rad2) * radius;
    return *this;
}

// Overrides the postfix ++ operator
Spiral Spiral::operator++(int) {
    Spiral tmp(*this);
    operator++();
    return tmp;
}

// Overrides the ostream << operator to output information about a spiral
ostream& operator<<(ostream& output, Spiral sp) {
    output << sp.get_text_x();
    output << "\t" << sp.get_text_y();
    output << "\t" <<  sp.get_text_angle();
    output << "\t" <<  sp.get_spiral_angle();
    return output;
}
