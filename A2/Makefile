CC = g++
CFLAGS = -Wall -std=c++11
LIBHARU = ./libharu
LFLAGS = -L$(LIBHARU)/src/
INCLUDE = $(LIBHARU)/include/
LIBS = -lhpdfs -lz -lm -lstdc++

spiralPDF: spiralPDF.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.o $(LFLAGS) -I$(INCLUDE) $(LIBS)
spiralPDF.o: spiralPDF.cpp Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -c spiralPDF.cpp $(LFLAGS) -I$(INCLUDE) $(LIBS)
Spiral.o: Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp
HaruPDF.o: HaruPDF.cpp $(INCLUDE)/hpdf.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp $(LFLAGS) -I$(INCLUDE) $(LIBS)
clean:
	rm -f spiralPDF *.o
