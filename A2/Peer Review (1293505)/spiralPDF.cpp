//Michael Swisher CS3505
//A2: Classes and Facades
#include "Spiral.h"
#include "HaruPDF.h"
#include <cstring>

int main(int argc , char **argv)
{
   Spiral s =  Spiral(240, 240 , 100);
   HaruPDF haru = HaruPDF(argv[0]);
   char* text = argv[1];
   unsigned int i;
   for(i = 0; i < strlen(text); i++)
   {
       ++s;
       haru.PlaceText(s.get_text_angle(), text[i], s.get_text_x(), s.get_text_y());
   }
   haru.SaveAndClean();
}
