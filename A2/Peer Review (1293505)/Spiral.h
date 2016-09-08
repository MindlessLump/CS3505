//Michael Swisher CS3505
//A2: Classes and Facades
#include <iostream>
class Spiral
{
private:
    //x position of the next letter
    double x;
    //y position of the next letter
    double y;
    //the current iteration in the spiral
    double i;
    //center of the spiral
    double centerX;
    //center of the spiral
    double centerY;
    //the starting radius
    double radius;
    //starting angle of the spiral
    double angle;
    //current spiral angle
    double sAngle;
    //current text angle
    double tAngle;


public:
    //constructs a spiral object with a center and radius
    Spiral(double centerX, double centerY, double radius);
    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();
    //iterates the spiral so the next char can be placed
    Spiral operator++();
    //iterates the sprial so the next char can be place
    Spiral operator++(int);
    //outputs the radius and text angle
    friend std::ostream& operator<< (std::ostream& os, const Spiral& spir);
};
