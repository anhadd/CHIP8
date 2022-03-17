CC = g++
CFLAGS = -lSDL2
DEPS = /include/*
OBJECTS = chip8.o input.o GUI.o SFX.o main.o


all: ../main

../main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o chip8
	rm -f ../main chip8
