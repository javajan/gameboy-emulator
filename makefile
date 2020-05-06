CC=gcc
CFLAGS= -Wall
DEPS = gameboy.h
OBJ = main.o gameboy.o instructions.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o gameboy $(OBJ) $(CFLAGS)

run: build
	./gameboy
	

.PHONY: clean
clean:
	rm gameboy $(OBJ)
