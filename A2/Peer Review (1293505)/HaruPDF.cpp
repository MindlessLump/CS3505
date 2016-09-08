//Michael Swisher CS3505
//A2: Classes and Facades
#include "HaruPDF.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
//Constructs a pdf with the given name
HaruPDF::HaruPDF(char name[])
{
    strcpy(fname, name);
    strcat(fname, ".pdf");
    pdf = HPDF_New(NULL, NULL);

    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading(page, 20);
    HPDF_Page_SetGrayStroke(page,0);

    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, font, 30);
}
//takes in a char, angle of text, and position x and y and places it on the pdf
void HaruPDF::PlaceText(double rad1, char c, double x, double y)
{
    HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);
    char buf[2];
    buf[0] = c;
    buf[1] = 0;
    HPDF_Page_ShowText(page,buf);
 }
//saves and ends the file
void HaruPDF::SaveAndClean()
{
    HPDF_Page_EndText(page);
    HPDF_SaveToFile(pdf, fname);
    HPDF_Free(pdf);
}
