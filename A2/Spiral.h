/*
 * Erik Martin
 * CS 3505
 * A2 - Classes and Facades
 */

#include <iostream>
using namespace std;

class Spiral {
    float angle2;
    float rad1, rad2;
    float x, y;
    float _centerX, _centerY;
    float radius;
public:
    Spiral(double centerX, double centerY, float startRad);
    Spiral& operator++();
    Spiral operator++(int);
    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();
    double get_text_cosine();
    double get_text_sine();
    friend ostream& operator<<(ostream& output, Spiral sp);
};
