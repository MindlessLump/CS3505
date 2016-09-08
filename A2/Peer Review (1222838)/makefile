LIBHARU =  ../libharu

spiralPDF: HaruPDF.o Spiral.o spiralPDF.o
	g++ -Wall -std=c++11 -o SpiralPDF SpiralPDF.o HaruPDF.o Spiral.o

Spiral.o: Spiral.cpp Spiral.h
	g++ -Wall -std=c++11 -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h $(LIBHARU)/include/hpdf.h
	g++ -Wall -std=c++11 -L$(LIBHARU)/src -I$(LIBHARU)/include -c HaruPDF.cpp

spiralPDF.o: spiralPDF.cpp Spiral.h HaruPDF.h $(LIBHARU)/include/hpdf.h
	g++ -Wall -std=c++11 -L$(LIBHARU)/src -I. -I$(LIBHARU)/include -c spiralPDF.cpp

clean:
	rm -f SpiralPDF *.o

test:
	./SpiralPDF "This is a test. I do not know what I shoudld write here.  I spelled should wrong"
