
BIN_FOLDER=bin
BIN = gameboy

SRC_DIR=src
OBJ_DIR=obj
INC_DIR=include

SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -lSDL2

_DEPS = gameboy.h instructions.h memory.h screen.h types.h util.h debugger.h interrupts.h joypad.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

_OBJ = gameboy.o instructions.o memory.o screen.o main.o debugger.o interrupts.o joypad.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -I$(INC_DIR) $(CFLAGS) -o $@ $<

build: $(OBJ)
	$(CC) $(OBJ_DIR)/*.o $(CFLAGS) -o $(BIN_FOLDER)/$(BIN)
	
run: build
	./$(BIN_FOLDER)/$(BIN)
	
clean:
	-rm $(OBJ_DIR)/*.o
