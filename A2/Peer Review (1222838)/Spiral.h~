/*
 * Naoki Tominaga
 * CS3505
 * Assignment A2
 */

#include <iostream>

class Spiral{
private:
    double center_X;
    double center_Y;
    double X;
    double Y;
    double radius;
    double spiralAngle;

public:
    Spiral(double centerX, double centerY, double rad0);
    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();
    Spiral& operator++();
    Spiral operator++(int);
    friend std::ostream& operator<<(std::ostream& output, Spiral spiral);
};
