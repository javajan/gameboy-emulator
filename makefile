CC=gcc
CFLAGS= -Wall -lSDL2
DEPS = gameboy.h util.h memory.h screen.h types.h
OBJ = main.o gameboy.o instructions.o memory.o screen.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o gameboy $(OBJ) $(CFLAGS)

run: build
	./gameboy
	

.PHONY: clean
clean:
	rm gameboy $(OBJ)
