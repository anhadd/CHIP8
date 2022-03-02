CC = g++
CFLAGS = -lSDL2
DEPS = /include/*
OBJECTS = chip8.o main.o


all: main

main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o chip8
