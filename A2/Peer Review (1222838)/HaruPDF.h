/*
 * Naoki Tominaga
 * CS3505
 * Assignment A2
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "hpdf.h"

class HaruPDF{
private:
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
public:
    HaruPDF();
    void WriteToPDF(const char* text, float txtAngle, float x, float y);
    void SaveToFile(const char* filename);
};
