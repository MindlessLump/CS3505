CC = g++
CFLAGS = -Wall -std=c++11
LIBHARU = ./libharu
LFLAGS = -L$(LIBHARU)/src/
INCLUDE = $(LIBHARU)/include/
LIBS = -lhpdfs -lz -lm -lstdc++

spiralPDF: spiralPDF.o ./Spiral.h Spiral.o ./HaruPDF.h HaruPDF.o
	$(CC) $(CLFAGS) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o $(LFLAGS) -I./ -I$(INCLUDE) $(LIBS)
Spiral.o: ./Spiral.h Spiral.cpp
	$(CC) $(CFLAGS) -c -I./ Spiral.cpp
HaruPDF.o: ./HaruPDF.h HaruPDF.cpp $(INCLUDE)/hpdf.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp $(LFLAGS) -I./ -I$(INCLUDE) $(LIBS)
spiralPDF.o: spiralPDF.cpp ./Spiral.h ./HaruPDF.h
	$(CC) $(CFLAGS) -c -I./ spiralPDF.cpp $(LFLAGS) -I$(INCLUDE) $(LIBS)
clean:
	rm -f spiralPDF *.o
test:
	./spiralPDF "The quick brown fox jumps over the lazy dog. More words make the spiral bigger and more comprehensive. The more the merrier."
