/*
 * Erik Martin
 * CS3505
 * A2 - Classes and Facades
 */

#include "hpdf.h"

// The HaruPDF class serves as an interface for building and saving PDFs,
// and adding text to the document page.
class HaruPDF {
    HPDF_Doc _pdf;
    HPDF_Page _page;
    char _fname[256];
    HPDF_Font _font;
public:
    HaruPDF(); // Default contructor
    HaruPDF(char fname[256]); // Constructor with given filename
    void addText(char buf[2], float rad1, float rad2, float x, float y);
    void saveAndClose();
}
