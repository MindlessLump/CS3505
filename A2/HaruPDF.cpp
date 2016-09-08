/*
 * Erik Martin
 * CS3505
 * A2 - Classes and Facades
 *
 * HaruPDF is a facade class for setting up a document, placing text on a page,
 * and saving the PDF. It serves as an interface between our spiral generation
 * class and the Haru library. If no filename is given,
 * it defaults to "HaruPDF.pdf".
 */

#include "HaruPDF.h"
#include <string.h>
#include "hpdf.h"

HaruPDF::HaruPDF() {
    strcat (_fname, "HaruPDF.pdf");
    _pdf = HPDF_New (NULL, NULL);
    _page = HPDF_AddPage (_pdf);
    HPDF_Page_SetSize (_page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    _font = HPDF_GetFont (_pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (_page, 20);
    HPDF_Page_SetGrayStroke (_page, 0);

    HPDF_Page_BeginText (_page);
    HPDF_Page_SetFontAndSize (_page, _font, 30);
}

HaruPDF::HaruPDF(char fname[256]) {
    strcpy (_fname, fname);
    strcat (_fname, ".pdf");
    _pdf = HPDF_New (NULL, NULL);
    _page = HPDF_AddPage (_pdf);
    HPDF_Page_SetSize (_page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    _font = HPDF_GetFont (_pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (_page, 20);
    HPDF_Page_SetGrayStroke (_page, 0);

    HPDF_Page_BeginText (_page);
    HPDF_Page_SetFontAndSize (_page, _font, 30);
}

void HaruPDF::addText(float cosine, float sine, float x, float y, char buf[2]) {
    HPDF_Page_SetTextMatrix (_page,
                            cosine, sine, -sine, cosine,
                            x, y);
    HPDF_Page_ShowText (_page, buf);
}

void HaruPDF::saveAndClose() {
    HPDF_Page_EndText (_page);
    HPDF_SaveToFile (_pdf, _fname);
    HPDF_Free (_pdf);
}
