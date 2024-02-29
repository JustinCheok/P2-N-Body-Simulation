CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = main.o Universe.o CelestialBody.o
DEPS = Universe.cpp CelestialBody.cpp main.cpp
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
EXE = NBody

all: $(OBJ)
$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
$(CC) $(CFLAGS) -o $@ $<

main.o: main.cpp
$(CC) $(CFLAGS) -o $@ $<

main: main.o Universe.o CelestialBody.o
$(CC) $(CFLAGS) $@ main.o Universe.o CelestialBody.o

clean:
rm $(OBJ) $(EXE)
