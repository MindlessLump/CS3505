//Michael Swisher CS3505
//A2: Classes and Facades
#include <iostream>
#include "hpdf.h"
class HaruPDF
{
 private:
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    char fname [256];

 public:
    HaruPDF(char name[]);
    void PlaceText(double rad1, char c, double x, double y);
    void SaveAndClean();
};
