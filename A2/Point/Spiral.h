/*
 * Erik Martin
 * CS 3505
 * A2 - Classes and Facades
 */

class Spiral {
    float angle2;
    float rad1, rad2;
    float x, y;
    unsigned int i;
    char fname[256];
    char* INPUT_TXT;
public:
    Spiral(double centerX, double centerY, float startRad);
    float operator++();
    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();
    friend ostream& operator<<(ostream& output, Spiral sp);
}
