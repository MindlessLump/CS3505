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
#include "HaruPDF.h"

using namespace std;

HaruPDF::HaruPDF(){
    // set up pdf
    pdf = HPDF_New(NULL, NULL);
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading(page, 20);
    HPDF_Page_SetGrayStroke(page, 0);
    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, font, 30);
}

void HaruPDF::WriteToPDF(const char* text, float txtAngle, float x, float y){
    // write to the pdf
    HPDF_Page_SetTextMatrix(page, cos(txtAngle), sin(txtAngle), -sin(txtAngle), cos(txtAngle), x , y);
    HPDF_Page_ShowText(page, text);
}

void HaruPDF::SaveToFile(const char* filename){
    // finished writing and now saving pdf
    HPDF_Page_EndText(page);
    HPDF_SaveToFile(pdf, filename);
    HPDF_Free(pdf);
}
