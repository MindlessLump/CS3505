LIBHARU = ../libharu

CCFLAGS = -std=c++11 -O2 -Wall

all: spiralPDF.o HaruPDF.o Spiral.o
	g++ $(CCFLAGS) -o spiralPDF spiralPDF.o HaruPDF.o Spiral.o -L ./$(LIBHARU)/src -I ./$(LIBHARU)/include -lhpdfs -lm -lz
	./spiralPDF "This assignment was a blast, I would really love to do another one just like this one to have a lot of fun"
spiralPDF.o: spiralPDF.cpp Spiral.h HaruPDF.h
	g++ $(CCFLAGS) -c spiralPDF.cpp -L ./$(LIBHARU)/src -I ./$(LIBHARU)/include -lhpdfs -lm -lz
HaruPDF.o: HaruPDF.h HaruPDF.cpp
	g++ $(CCFLAGS) -c HaruPDF.cpp -L ./$(LIBHARU)/src -I ./$(LIBHARU)/include -lhpdfs -lm -lz
Spiral.o: Spiral.h Spiral.cpp
	g++ $(CCFLAGS) -c Spiral.cpp -L ./$(LIBHARU)/src -I ./$(LIBHARU)/include -lhpdfs -lm -lz
clean:
	-rm *.o $(objects) spiralPDF
