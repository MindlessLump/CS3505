/*
 * Erik Martin
 * CS3505
 * A2 - Classes and Facades
 */

#include <iostream>
#include <string.h>
using namespace std;
#include "HaruPDF.h"
#include "Spiral.h"

int main(int argc, char **argv) {
    int i;

    // Create new PDF file with program name
    HaruPDF pdf(argv[0]);

    // Get input text from command line
    const char* INPUT_TXT = argv[1];
    const int strLen = strlen(INPUT_TXT);

    // Start text spiral calculations
    Spiral spiral(210.0, 310.0, 100.0);

    // Iterate through input string and place text
    for (i = 0; i < strLen; i++) {
        // Place character
        char buf[2] = {INPUT_TXT[i], 0};
        pdf.addText(spiral.get_text_cosine(),  spiral.get_text_sine(),
                    spiral.get_text_x(), spiral.get_text_y(), buf);

        // Output position to console
        cout << spiral << endl;

        // Update position
        ++spiral;
    }

    return 0;
}
